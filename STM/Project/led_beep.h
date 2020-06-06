#include <string.h>
#include "stm32f10x.h"
#include "usart.h"
#include "Types.h"


//ledµ∆≈‰÷√
#define 	GREEN_LED_OFF 	LED1_ONOFF(Bit_SET)
#define 	BLUE_LED_OFF 		LED2_ONOFF(Bit_SET)
#define 	RED_LED_OFF 		LED3_ONOFF(Bit_SET)

#define 	GREEN_LED_ON 		LED1_ONOFF(Bit_RESET)
#define 	BLUE_LED_ON 		LED2_ONOFF(Bit_RESET)
#define 	RED_LED_ON 			LED3_ONOFF(Bit_RESET)


void CON_LED(int pro);
void SET_LED(char ledR, char ledG, char ledB);
void CON_BEEP(int pro);
void led_beep_time_work(void);
void led_beep_force(void);

#define LED_PRO_B_S			CON_LED(1);
#define LED_PRO_GB_S		CON_LED(2);
#define LED_PRO_RB_S		CON_LED(3);
#define LED_PRO_R_D			CON_LED(4);
#define LED_PRO_G_S			CON_LED(5);
#define LED_PRO_RG_A		CON_LED(6);
#define LED_PRO_G_L			CON_LED(7);
#define LED_PRO_R_L			CON_LED(8);
#define LED_PRO_RGB_SL	CON_LED(9);

#define BEEP_PRO_S			CON_BEEP(1);
#define BEEP_PRO_D			CON_BEEP(2);
#define BEEP_PRO_L			CON_BEEP(3);
#define BEEP_PRO_SL			CON_BEEP(4);

#define GROUP_PRO_FAILED   led_beep_force();CON_BEEP(2);CON_LED(4);
#define GROUP_PRO_SUCCEED  led_beep_force();CON_BEEP(1);CON_LED(5);
#define GROUP_PRO_RFID   	 led_beep_force();CON_BEEP(1);CON_LED(5);
#define GROUP_PRO_FINGER   led_beep_force();CON_BEEP(1);CON_LED(2);
#define GROUP_PRO_BTN   	 led_beep_force();CON_BEEP(1);CON_LED(3);

#define GROUP_PRO_NET_SUCCEED 		led_beep_force();CON_BEEP(5);CON_LED(12);
#define GROUP_PRO_NET_FAILED   	 	led_beep_force();CON_BEEP(6);CON_LED(13);
