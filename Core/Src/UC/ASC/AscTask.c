/**
  ******************************************************************************
  * @file           : 
  * @brief         : 
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <AscTask.h>
/* Code here ---------------------------------------------------------*/

void TaskManager(void)
{
	if(gval_flag_tic_fault1S || gval_flag_tic_fault100mS || gval_flag_tic_fault10mS || gval_flag_tic_fault1mS)
	{
//		printf("Task Execution Timeout!!\r\n");	//Task Execution Timeout
//		HAL_Delay(500);

		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_8, 0);	//Timeout indicator ON

		gval_flag_tic_fault1S = 0;
		gval_flag_tic_fault100mS = 0;
		gval_flag_tic_fault10mS = 0;
		gval_flag_tic_fault1mS = 0;
	}

	if(gval_flag_tic_1S)
	{
		Task1S();

		gval_flag_tic_1S = OFF;
	}

	if(gval_flag_tic_100mS)
	{
		Task100mS();
		gval_flag_tic_100mS = OFF;
	}

	if(gval_flag_tic_10mS)
	{
		Task10mS();
		gval_flag_tic_10mS = OFF;
	}

	if(gval_flag_tic_1mS)
	{
		Task1mS();

		gval_flag_tic_1mS = OFF;
	}
}

void Task1S(void)			//1초간격 수행루틴
{
	uint8_t tx_str_temp[100];
	static unsigned char i=0;

	//SampleTestDisplay();
}
void Task100mS(void)		//0.1초간격 수행루틴
{
	//uint8_t tx_str_temp[100];

	GPIOC->ODR ^= GPIO_PIN_0;	//Blinked status LED
}
void Task10mS(void)			//0.01초간격 수행루틴
{
}
void Task1mS(void)			//0.001초간격 수행루틴
{
	GetADCResult();

	SET_PWM_VOL(1, PID_Controll(0,CurAdcOutput[0]));
	SET_PWM_VOL(2, PID_Controll(1,CurAdcOutput[1]));
	SET_PWM_VOL(3, PID_Controll(2,CurAdcOutput[2]));
	SET_PWM_VOL(4, PID_Controll(3,CurAdcOutput[3]));
	SET_PWM_VOL(5, PID_Controll(4,CurAdcOutput[4]));
	SET_PWM_VOL(6, PID_Controll(5,CurAdcOutput[5]));

	if(g_bReceived1)	UART1_RXServiceRoutine();	//UART1 RX Service Routine
	if(g_bReceived2)	UART2_RXServiceRoutine();	//UART2 RX Service Routine
}
/* End Code ---------------------------------------------------------*/
