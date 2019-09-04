
#define VERSION "0.3.1"
//#include <String.h>
//#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <ArduinoJson.h>
#include <FS.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
//#include <TimeLib.h>
#include <Ticker.h>

#include <AsyncMqttClient.h>
#include <btn.h>

#include <MFRC522.h>
MFRC522 mfrc522 = MFRC522();
byte buffer[18];
byte block;
byte waarde[64][16];
MFRC522::StatusCode status;
MFRC522::MIFARE_Key key;


#include <Wiegand.h>
WIEGAND wg;
#include "rfid125kHz.h"
RFID_Reader RFIDr;


int readertype;
int relayPin;

#include <NTP.h>
NtpClient NTP;

String remoteIP ;

#ifndef NoNFC
#include <Wire.h>
#include <SPI.h>
#include <PN532.h>
#define PN532_SS   			(15)
#define PN532_IRQ   		(4)
#define PN532_RESET 	(3)  
NFC nfc(PN532_SS);
#endif

//#include <SoftwareSerial.h>
// #include <RDM6300.h>
// #define RFID_RX_PIN 13
// #define RFID_TX_PIN 15
// RDM6300 RDM(RFID_RX_PIN, RFID_TX_PIN);


//#ifndef OFFICIALBOARD
//#endif
 // #define DEBUG

// these are from vendors
#include "webh/glyphicons-halflings-regular.woff.gz.h"
#include "webh/required.css.gz.h"
#include "webh/required.js.gz.h"

// these are from us which can be updated and changed
#include "webh/rfid.js.gz.h"
#include "webh/item.htm.gz.h"
#include "webh/index.html.gz.h"

#ifdef ESP8266
extern "C" {
	#include "user_interface.h"
}
#endif


AsyncMqttClient mqttClient;
Ticker mqttReconnectTimer;
WiFiEventHandler wifiDisconnectHandler, wifiConnectHandler;
Bounce openLockButton;

AsyncWebServer server(80);
AsyncWebSocket ws("/ws");

unsigned long blink_ = millis();
bool wifiFlag = false;
bool configMode = false;
int wmode;
uint8_t wifipin = 255;

uint8_t doorstatpin = 255;
uint8_t lastDoorState = 0;

uint8_t openlockpin = 255;

#define LEDoff HIGH
#define LEDon LOW

// Variables for whole scope
const char *http_username = "admin";
char *http_pass = NULL;
unsigned long previousMillis = 0;
unsigned long previousLoopMillis = 0;
unsigned long currentMillis = 0;
unsigned long cooldown = 0;
unsigned long deltaTime = 0;
unsigned long uptime = 0;
bool shouldReboot = false;
bool activateRelay = false;
bool deactivateRelay = false;
bool inAPMode = false;
bool isWifiConnected = false;
unsigned long autoRestartIntervalSeconds = 0;

bool wifiDisabled = true;
bool doDisableWifi = false;
bool doEnableWifi = false;
bool timerequest = false;
bool formatreq = false;
unsigned long wifiTimeout = 0;
unsigned long wiFiUptimeMillis = 0;
char *deviceHostname = NULL;

int mqttenabled = 0;
char *mqttTopic = NULL;
char *mhs = NULL;
char *muser = NULL;
char *mpas = NULL;
int mport;

int lockType;
int relayType;
unsigned long activateTime;
int timeZone;

unsigned long nextbeat = 0;

unsigned long interval 	= 1800;  // Add to GUI & json config
bool mqttEvents = false; // Sends events over MQTT disables SPIFFS file logging



#include "log.esp"
#include "mqtt.esp"
#include "helpers.esp"
#include "wsResponses.esp"
#include "rfid.esp"
#include "wifi.esp"
#include "config.esp"
#include "websocket.esp"
#include "webserver.esp"
#include "door.esp"


void ICACHE_FLASH_ATTR setup()
{
	
#ifdef DEBUG

	Serial.begin(115200);
	Serial.println();
	uint32_t realSize = ESP.getFlashChipRealSize();
	uint32_t ideSize = ESP.getFlashChipSize();
	FlashMode_t ideMode = ESP.getFlashChipMode();
	Serial.printf("Flash real id:   %08X\n", ESP.getFlashChipId());
	Serial.printf("Flash real size: %u\n\n", realSize);
	Serial.printf("Flash ide  size: %u\n", ideSize);
	Serial.printf("Flash ide speed: %u\n", ESP.getFlashChipSpeed());
	Serial.printf("Flash ide mode:  %s\n", (ideMode == FM_QIO ? "QIO" : ideMode == FM_QOUT ? "QOUT" : ideMode == FM_DIO ? "DIO" : ideMode == FM_DOUT ? "DOUT" : "UNKNOWN"));
	if (ideSize != realSize)
	{
		Serial.println("Flash Chip configuration wrong!\n");
	}
	else
	{
		Serial.println("Flash Chip configuration ok.\n");
	}
#endif

	if (!SPIFFS.begin())
	{
#ifdef DEBUG
		Serial.print(F("[ 警告 ] Formatting filesystem..."));
#endif
		if (SPIFFS.format())
		{
			writeEvent("警告", "sys", "Filesystem formatted", "");
#ifdef DEBUG
			Serial.println(F(" completed!"));
#endif
		}
		else
		{
			writeEvent("错误", "sys", "文件系统无法格式化", "");
#ifdef DEBUG
			Serial.println(F("[ 警告 ] Could not format filesystem!"));
#endif
		}
	}
	wifiDisconnectHandler = WiFi.onStationModeDisconnected(onWifiDisconnect);
	wifiConnectHandler = WiFi.onStationModeConnected(onWifiConnect);
	configMode = loadConfiguration();
	if (!configMode)
	{
		fallbacktoAPMode();
		writeEvent("提醒", "sys", "进入AP配置模式", "");
		configMode = false;
	}
	else 
	{
		writeEvent("完成", "sys", "系统初始化完成", "");
		configMode = true;
	}
	setupWebServer();
}

void ICACHE_RAM_ATTR loop()
{
	currentMillis = millis();
	deltaTime = currentMillis - previousLoopMillis;
	uptime = NTP.getUptimeSec();
	previousLoopMillis = currentMillis;

	openLockButton.update();
	if (openLockButton.fell())
	{
#ifdef DEBUG
		Serial.println("Button has been pressed");
#endif
		writeLatest("", "(used open/close button)", 1);
		activateRelay = true;
	}

	if (wifipin != 255 && configMode && !wmode)
	{
		if (!wifiFlag)
		{
			if ((currentMillis - blink_) > 500)
			{
				blink_ = currentMillis;
				digitalWrite(wifipin, !digitalRead(wifipin));
			}
		}
		else
		{
			if (!(digitalRead(wifipin)==LEDon)) digitalWrite(wifipin, LEDon);
		}
	}
	 doorStatus(doorstatpin);
	// if (doorstatpin != 255)
	// {
	// 	doorStatus(doorstatpin);
	// 	delay(1);
	// }

	if (currentMillis >= cooldown)
	{
		rfidloop();
	}

	// Continuous relay mode
	if (lockType == 1)
	{
		if (activateRelay)
		{
			// currently OFF, need to switch ON
			if (digitalRead(relayPin) == !relayType)
			{
				digitalWrite(relayPin, relayType);
				#ifdef DEBUG
				Serial.print("activating relay mili : ");
				Serial.println(millis());
				#endif
			}
			else	// currently ON, need to switch OFF
			{
				digitalWrite(relayPin, !relayType);
				#ifdef DEBUG
				Serial.print("deactivating relay mili : ");
				Serial.println(millis());
				#endif			
			}
			activateRelay = false;
		}
	}
	else if (lockType == 0)	// momentary relay mode
	{
		if (activateRelay)
		{
#ifdef DEBUG
			Serial.print("activating relay momentary mili : ");
			Serial.println(millis());
#endif
			digitalWrite(relayPin, relayType);
			previousMillis = millis();
			activateRelay = false;
			deactivateRelay = true;
		}
		else if ((currentMillis - previousMillis >= activateTime) && (deactivateRelay))
		{
#ifdef DEBUG
			Serial.println(currentMillis);
			Serial.println(previousMillis);
			Serial.println(activateTime);
			Serial.println(activateRelay);
			Serial.print("deactivate relay after mili : ");
			Serial.println(millis());
#endif
			digitalWrite(relayPin, !relayType);
			deactivateRelay = false;
		}
	}
	if (formatreq)
	{
		#ifdef DEBUG
				Serial.println(F("[ 警告 ] 恢复出厂设置..."));
		#endif
		SPIFFS.end();
		ws.enable(false);
		SPIFFS.format();
		ESP.restart();
	}
	if (timerequest)
	{
		timerequest = false;
		sendTime();
	}

	if (autoRestartIntervalSeconds > 0 && uptime > autoRestartIntervalSeconds * 1000)
	{
		char buff[12];
		sprintf(buff, "间隔 %d s", autoRestartIntervalSeconds);
		String  info =buff;
		writeEvent("提醒", "reboot", "设备将按计划重启", info);
		#ifdef DEBUG
		Serial.println(F("[ 警告 ] 设备重启..."));
		#endif
		shouldReboot = true;
	}
	if (shouldReboot)
	{
		//writeEvent("提醒", "reboot", "系统计划重启", "");
		//#ifdef DEBUG
		//Serial.println(F("[ 提醒 ] 即将重启..."));
		//#endif
		ESP.restart();
	}

	if (isWifiConnected)
	{
		wiFiUptimeMillis += deltaTime;
	}

	if (wifiTimeout > 0 && wiFiUptimeMillis > (wifiTimeout * 1000) && isWifiConnected == true)
	{
		writeEvent("提醒", "WiFi", "WiFi 将关闭", "");
		doDisableWifi = true;
	}
	if (doDisableWifi == true)
	{
		doDisableWifi = false;
		wiFiUptimeMillis = 0;
		disableWifi();
	}
	else if (doEnableWifi == true)
	{
		writeEvent("提醒", "wifi", "WiFi将打开", "");
		doEnableWifi = false;
		if (!isWifiConnected)
		{
			wiFiUptimeMillis = 0;
			enableWifi();
		}
	}

	if (mqttenabled == 1)
	{
		if (mqttClient.connected())
		{
			if ((unsigned)now() > nextbeat)
			{
				mqtt_publish_heartbeat(now());
				nextbeat = (unsigned)now() + interval;
#ifdef DEBUG
				Serial.print("[ 提醒 ] 心跳= ");
				Serial.println(nextbeat);
#endif
			}
		}
	}
}
