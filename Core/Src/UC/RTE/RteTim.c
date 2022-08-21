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
/**

/* Includes ------------------------------------------------------------------*/
#include <RteTim.h>
/* Code here ---------------------------------------------------------*/

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
//	static uint8_t	tval_cnt_tim2_debug = 0;

	if(htim->Instance == TIM2)
	{
		tval_cnt_tim2_period_1S++;
		tval_cnt_tim2_period_100mS++;
		tval_cnt_tim2_period_10mS++;
		tval_cnt_tim2_period_1mS++;

		if(tval_cnt_tim2_period_1S >= 9999)		//���ͷ�Ʈ �ֱ� = 1S
		{
			if(gval_flag_tic_1S != ON)	gval_flag_tic_1S = ON;
			else gval_flag_tic_fault1S = ON;

			tval_cnt_tim2_period_1S = 0;
		}
		if(tval_cnt_tim2_period_100mS >= 999)	//���ͷ�Ʈ �ֱ� = 100mS
		{
			if(gval_flag_tic_100mS != ON)	gval_flag_tic_100mS = ON;
			else	gval_flag_tic_fault100mS = ON;

			tval_cnt_tim2_period_100mS = 0;
		}
		if(tval_cnt_tim2_period_10mS >= 99)		//���ͷ�Ʈ �ֱ� = 10mS
		{
			if(gval_flag_tic_10mS != ON)	gval_flag_tic_10mS = ON;
			else gval_flag_tic_fault10mS = ON;

			tval_cnt_tim2_period_10mS = 0;
		}
		if(tval_cnt_tim2_period_1mS >= 9)		//���ͷ�Ʈ �ֱ� = 1mS
		{
			if(gval_flag_tic_1mS != ON)		gval_flag_tic_1mS = ON;
			else gval_flag_tic_fault1mS = ON;

			tval_cnt_tim2_period_1mS = 0;
		}
	}
}
/* End Code ---------------------------------------------------------*/
