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
#include "main.h"
#include "tim.h"
/* Macro -------------------------------------------------------------*/
#define ON 	1
#define OFF 0
/* Typedef -----------------------------------------------------------*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

/* Variables ---------------------------------------------------------*/

uint32_t 	gval_flag_tic_1S;
uint32_t 	gval_flag_tic_100mS;
uint32_t 	gval_flag_tic_10mS;
uint32_t	gval_flag_tic_1mS;

uint16_t 	gval_flag_tic_fault1S;
uint16_t 	gval_flag_tic_fault100mS;
uint16_t 	gval_flag_tic_fault10mS;
uint16_t 	gval_flag_tic_fault1mS;

uint16_t	tval_cnt_tim2_period_1S;
uint16_t	tval_cnt_tim2_period_100mS;
uint16_t	tval_cnt_tim2_period_10mS;
uint16_t	tval_cnt_tim2_period_1mS;


/* Code here ---------------------------------------------------------*/

/* End Code ---------------------------------------------------------*/
