# [RFID](https://github.com/QFUL/RFID)

适配多种读卡器

RDM6300 125KHz

WeMos D1上数字引脚
D3与D15、D4与D14、D5与D13、D6与D12、D7与D11、D9与板载LED 它们两两之间是互通的。 

```
static const uint8_t PIN_D0 = 3;            //RX
static const uint8_t PIN_D1 = 1;            //TX
static const uint8_t PIN_D2 = 16;           
static const uint8_t PIN_D3_D15 = 5;        //SCL
static const uint8_t PIN_D4_D14 = 4;        //SDA
static const uint8_t PIN_D5_D13 = 14;       //SCK
static const uint8_t PIN_D6_D12 = 12;       //MISO
static const uint8_t PIN_D7_D11 = 13;       //MOSI  
static const uint8_t PIN_D8 = 0;
static const uint8_t PIN_D9_LED = 2;        //LED
static const uint8_t PIN_D10 = 15;          //SS

static const uint8_t PIN_A0 = 17;

```
https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/

### interface

| ESP8266 | NodeMcu/WeMos | Wiegand | PN532 | MFRC522 | RDM6300 | 
|--------:|:-------------:|:-------:|:-----:|:-------:|:-------:|
| GPIO-15 | D8            |         | SS    | SDA/SS  |         |
| GPIO-13 | D7            | D0      | MOSI  | MOSI    |         |
| GPIO-12 | D6            | D1      | MISO  | MISO    |         |
| GPIO-14 | D5            |         | SCK   | SCK     |         |
| GPIO-04 | D2            |         |       |         |         |
| GPIO-05 | D1            |         |       |         |         |
| GPIO-03 | RX            |         |       |         | TX      |

```
sudo usermod -aG  dialout  user
pip install esptool
esptool.py --port /dev/ttyUSB0 -b 921600 write_flash 0x0 ./bin/blank4mb.bin

```

```
platformio run -t clean
platformio run -e generic -t upload
platformio  device monitor
```

Restore some randomly generated user data on File System worth:

1000  userfile 
4 Bytes long UID 
4 bytes random Unix Time Stamp，"access type" 1 byte integer "1" or "0".
Total 122,880 Bytes

At least 1000 unique User (RFID Tag) can be handled

