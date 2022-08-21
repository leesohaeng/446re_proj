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
#include <AscCDD.h>
/* Code here ---------------------------------------------------------*/
int32_t PID_Controll(uint8_t ch,int32_t Comparison_Value)
{
	err_P[ch] = Comparison_Value - PID_Target[ch];
	err_I[ch] += err_P[ch];
	if(err_I[ch] < -1000000)	err_I[ch] = -1000000;
	if(err_I[ch] > 1000000)	err_I[ch] = 1000000;
	err_D[ch] = err_B[ch] - err_P[ch];
	err_B[ch] = err_P[ch];

	PID_New_Value[ch] = ((err_P[ch] * PID_PV) + (err_I[ch] * PID_IV) + (err_D[ch] * PID_DV));

	PID_New_Value[ch] = PID_New_Value[ch] * (-1);

	if(PID_New_Value[ch] >= 9999)	PID_New_Value[ch] = 9999;
	else if(PID_New_Value[ch] <= 0)	PID_New_Value[ch] = 0;

	return PID_New_Value[ch];
}
/* Code here ---------------------------------------------------------*/
