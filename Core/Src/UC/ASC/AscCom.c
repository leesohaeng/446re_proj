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
#include <AscCom.h>
/* Code here ---------------------------------------------------------*/
void UART1_RXServiceRoutine(void)
{

	uint8_t tx_str_temp[100];
	uint8_t ch = 0;
	uint16_t pwm_val_temp = 0;

	switch(g_strData1[0])
	{
		case '1'  :	//외부 ADValue 응답
			ch = g_strData1[1] - 0x30;

			tx_str_temp[0] = 0x28;
			tx_str_temp[1] = 0x32;

			tx_str_temp[2] = (ExtAdcInput[ch] / 100);
			tx_str_temp[3] = (ExtAdcInput[ch] - (tx_str_temp[2] * 100)) / 10;
			tx_str_temp[4] = (ExtAdcInput[ch] - (tx_str_temp[2] * 100) - (tx_str_temp[3] * 10));

			tx_str_temp[2] += 0x30;
			tx_str_temp[3] += 0x30;
			tx_str_temp[4] += 0x30;

			tx_str_temp[5] = 0x29;
			tx_str_temp[6] = 0x00;


			HAL_UART_Transmit(&huart1, &tx_str_temp, strlen(tx_str_temp),10);
		break;

		case '3' :
			if(g_strData1[1] == '1')			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,ON);
			else if(g_strData1[1] == '0')	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,OFF);

			if(g_strData1[2] == '1')			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_1,ON);
			else if(g_strData1[2] == '0')	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_1,OFF);

			if(g_strData1[3] == '1')			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_2,ON);
			else if(g_strData1[3] == '0')	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_2,OFF);

			if(g_strData1[4] == '1')			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,ON);
			else if(g_strData1[4] == '0')	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,OFF);

			if(g_strData1[5] == '1')			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,ON);
			else if(g_strData1[5] == '0')	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,OFF);

			if(g_strData1[6] == '1')			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,ON);
			else if(g_strData1[6] == '0')	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,OFF);

			if(g_strData1[7] == '1')			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_6,ON);
			else if(g_strData1[7] == '0')	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_6,OFF);

			if(g_strData1[8] == '1')			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,ON);
			else if(g_strData1[8] == '0')	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,OFF);

		break;

		case '4' :
			ch = (g_strData1[1] - 0x30);
			pwm_val_temp = ((g_strData1[2] - 0x30) * 1000) + ((g_strData1[3] - 0x30) * 100) + ((g_strData1[4] - 0x30) * 10) + (g_strData1[5] - 0x30);

			if(pwm_val_temp >= curlimit)	pwm_val_temp = curlimit;
			else if(pwm_val_temp <= 100)	pwm_val_temp = 0;

			PID_Target[ch] = pwm_val_temp;
		break;

		case '5' :
			if(g_strData1[1] == 0x30)		canbypass2uart = 0;
			else if(g_strData1[1] == 0x31)	canbypass2uart = 1;
		break;

		case '6' :
			memset(tx_str_temp, 0x00, 10);

			for(char i=0;i<=7;i++)
			{
				tx_str_temp[i] = g_strData1[i+1];
			}
			CAN_TX(&tx_str_temp[0]);
		break;

		case '7' :
			ch = g_strData1[1] - 0x30;

			tx_str_temp[0] = 0x28;
			tx_str_temp[1] = 0x38;

			tx_str_temp[2] = (CurAdcOutput[ch] / 1000);
			tx_str_temp[3] = (CurAdcOutput[ch] - (tx_str_temp[2] * 1000)) / 100;
			tx_str_temp[4] = (CurAdcOutput[ch] - (tx_str_temp[2] * 1000) - (tx_str_temp[3] * 100)) / 10;
			tx_str_temp[5] = (CurAdcOutput[ch] - (tx_str_temp[2] * 1000) - (tx_str_temp[3] * 100) - (tx_str_temp[4] * 10));

			tx_str_temp[2] += 0x30;
			tx_str_temp[3] += 0x30;
			tx_str_temp[4] += 0x30;
			tx_str_temp[5] += 0x30;

			tx_str_temp[6] = 0x29;
			tx_str_temp[7] = 0x00;

			HAL_UART_Transmit(&huart1, &tx_str_temp, strlen(tx_str_temp),10);
		break;

		default:
		break;
	}

	g_bReceived1 = OFF;
}

void UART2_RXServiceRoutine(void)
{

	uint8_t tx_str_temp[100];
	uint8_t ch = 0;
	uint16_t pwm_val_temp = 0;

	switch(g_strData2[0])
	{
		case '1'  :	//외부 ADValue 응답
			ch = g_strData2[1] - 0x30;

			tx_str_temp[0] = 0x28;
			tx_str_temp[1] = 0x32;

			tx_str_temp[2] = (ExtAdcInput[ch] / 100);
			tx_str_temp[3] = (ExtAdcInput[ch] - (tx_str_temp[2] * 100)) / 10;
			tx_str_temp[4] = (ExtAdcInput[ch] - (tx_str_temp[2] * 100) - (tx_str_temp[3] * 10));

			tx_str_temp[2] += 0x30;
			tx_str_temp[3] += 0x30;
			tx_str_temp[4] += 0x30;

			tx_str_temp[5] = 0x29;
			tx_str_temp[6] = 0x00;

			printf("%s\r\n",tx_str_temp);
		break;

		case '3' :
			if(g_strData2[1] == '1')			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,ON);
			else if(g_strData2[1] == '0')	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_0,OFF);

			if(g_strData2[2] == '1')			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_1,ON);
			else if(g_strData2[2] == '0')	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_1,OFF);

			if(g_strData2[3] == '1')			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_2,ON);
			else if(g_strData2[3] == '0')	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_2,OFF);

			if(g_strData2[4] == '1')			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,ON);
			else if(g_strData2[4] == '0')	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_3,OFF);

			if(g_strData2[5] == '1')			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,ON);
			else if(g_strData2[5] == '0')	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_4,OFF);

			if(g_strData2[6] == '1')			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,ON);
			else if(g_strData2[6] == '0')	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,OFF);

			if(g_strData2[7] == '1')			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_6,ON);
			else if(g_strData2[7] == '0')	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_6,OFF);

			if(g_strData2[8] == '1')			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,ON);
			else if(g_strData2[8] == '0')	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_7,OFF);
		break;

		case '4' :
			ch = (g_strData2[1] - 0x30);
			pwm_val_temp = ((g_strData2[2] - 0x30) * 1000) + ((g_strData2[3] - 0x30) * 100) + ((g_strData2[4] - 0x30) * 10) + (g_strData2[5] - 0x30);

			if(pwm_val_temp >= curlimit)	pwm_val_temp = curlimit;
			else if(pwm_val_temp <= 100)	pwm_val_temp = 0;

			PID_Target[ch] = pwm_val_temp;
		break;

		case '5' :
			if(g_strData2[1] == 0x30)		canbypass2uart = 0;
			else if(g_strData2[1] == 0x31)	canbypass2uart = 1;
		break;

		case '6' :
			memset(tx_str_temp, 0x00, 10);

			for(char i=0;i<=7;i++)
			{
				tx_str_temp[i] = g_strData2[i+1];
			}
			CAN_TX(&tx_str_temp[0]);
		break;

//		case '7' :
//			ch = g_strData2[1] - 0x30;
//
//			tx_str_temp[0] = 0x28;
//			tx_str_temp[1] = 0x38;
//
//			tx_str_temp[2] = (CurAdcOutput[ch] / 1000);
//			tx_str_temp[3] = (CurAdcOutput[ch] - (tx_str_temp[2] * 1000)) / 100;
//			tx_str_temp[4] = (CurAdcOutput[ch] - (tx_str_temp[2] * 1000) - (tx_str_temp[3] * 100)) / 10;
//			tx_str_temp[5] = (CurAdcOutput[ch] - (tx_str_temp[2] * 1000) - (tx_str_temp[3] * 100) - (tx_str_temp[4] * 10));
//
//			tx_str_temp[2] += 0x30;
//			tx_str_temp[3] += 0x30;
//			tx_str_temp[4] += 0x30;
//			tx_str_temp[5] += 0x30;
//
//			tx_str_temp[6] = 0x29;
//			tx_str_temp[7] = 0x00;
//
//			printf("%s\r\n",tx_str_temp);
//		break;

		default:
		break;
	}

	g_bReceived2 = OFF;
}

/* End Code ---------------------------------------------------------*/
