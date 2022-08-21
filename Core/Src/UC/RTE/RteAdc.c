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
#include <RteAdc.h>
/* Code here ---------------------------------------------------------*/
void GetADCResult(void)
{
	unsigned char i=0;

	for(i=0;i<10;i++)
	{
		if(gval_adc_1[i] <= 410) 	ExtAdcInput[i] = 0;
		else
		{
			ExtAdcInput[i] = (gval_adc_1[i] - 410) / 31.9;
			if(ExtAdcInput[i] >= 100)	ExtAdcInput[i] = 100;
		}
	}

	//CurAdcOutput[0] = (gval_adc_2[5] / 1.030);
	//CurAdcOutput[1] = (gval_adc_2[0] / 1.030);
	//CurAdcOutput[2] = (gval_adc_2[1] / 1.030);
	//CurAdcOutput[3] = (gval_adc_2[2] / 1.030);
	//CurAdcOutput[4] = (gval_adc_2[3] / 1.030);
	//CurAdcOutput[5] = (gval_adc_2[4] / 1.030);

	CurAdcOutput[0] = (gval_adc_2[5] * 0.8302 + 10.176);
	CurAdcOutput[1] = (gval_adc_2[0] * 0.8302 + 10.176);
	CurAdcOutput[2] = (gval_adc_2[1] * 0.8302 + 10.176);
	CurAdcOutput[3] = (gval_adc_2[2] * 0.8302 + 10.176);
	CurAdcOutput[4] = (gval_adc_2[3] * 0.8302 + 10.176);
	CurAdcOutput[5] = (gval_adc_2[4] * 0.8302 + 10.176);

	for(i=0;i<6;i++)
	{
		if(CurAdcOutput[i] <= 100)	CurAdcOutput[i] = 0;
	}
}
/* End Code ---------------------------------------------------------*/
