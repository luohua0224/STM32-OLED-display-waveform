#include "bsp_led.h"
#include "bsp_usart.h"
#include "bsp_systick.h"
#include "OLED_I2C.h"
#include "bsp_i2c_gpio.h"
#include "bsp_adc.h"
#include "bsp_advanced_timer.h"
#include <math.h>

#define pi 3.1415926535
#define accur 0.015295//accur=18*3.3/4096��3.3/4096����ADC�������ȣ�18��Ϊ���ò���ת��һ���ܹ���ʾ���ʵ�λ�ӣ�
extern uint16_t ConvData;//ADC��������
extern unsigned char BMP1[];
int main()
{
	uint8_t x;
	LED_Init();
	USARTx_Init();
	OLED_Init();					 /* OLED��ʼ�� */
	ADCx_Init();
	AdvancedTim_Init();
	Before_State_Update(accur*ConvData);
	OLED_CLS();   //����
	while(1)
	{
		for(x=0;x<128;x=(x+1)%128)
		{
			OLED_DrawWave(x,accur*ConvData);//������
		
		}
	}
}
