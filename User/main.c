#include "bsp_led.h"
#include "bsp_usart.h"
#include "bsp_systick.h"
#include "OLED_I2C.h"
#include "bsp_i2c_gpio.h"
#include "bsp_adc.h"
#include "bsp_advanced_timer.h"
#include <math.h>

#define pi 3.1415926535
#define accur 0.015295//accur=18*3.3/4096（3.3/4096就是ADC采样精度，18是为了让波形转化一下能够显示在适当位子）
extern uint16_t ConvData;//ADC采样数据
extern unsigned char BMP1[];
int main()
{
	uint8_t x;
	LED_Init();
	USARTx_Init();
	OLED_Init();					 /* OLED初始化 */
	ADCx_Init();
	AdvancedTim_Init();
	Before_State_Update(accur*ConvData);
	OLED_CLS();   //清屏
	while(1)
	{
		for(x=0;x<128;x=(x+1)%128)
		{
			OLED_DrawWave(x,accur*ConvData);//画波形
		
		}
	}
}
