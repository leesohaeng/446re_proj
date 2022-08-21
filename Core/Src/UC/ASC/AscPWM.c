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
#include <AscPWM.h>
/* Code here ---------------------------------------------------------*/

void SET_PWM_VOL(unsigned char ch, unsigned int POW)
{
	switch(ch)
	{
		case 1:
			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_1, POW);
		break;

		case 2:
			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_2, POW);
		break;

		case 3:
			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_3, POW);
		break;

		case 4:
			__HAL_TIM_SetCompare(&htim3, TIM_CHANNEL_4, POW);
		break;

		case 5:
			__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_1, POW);
		break;

		case 6:
			__HAL_TIM_SetCompare(&htim4, TIM_CHANNEL_2, POW);
		break;

		default:
		break;
	}
}


/* End Code ---------------------------------------------------------*/
