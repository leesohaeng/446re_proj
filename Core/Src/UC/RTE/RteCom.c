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
#include <RteCom.h>
/* Code here ---------------------------------------------------------*/
//
//int __io_putchar(int ch)
//{
// HAL_UART_Transmit(&huart1, (uint8_t *)&ch, 1, 0xFFFF);
// return ch;
//}
void CAN_INIT(void)
{
	//CAN ���� ������
	canFilter1.FilterMaskIdHigh = 0x000 << 5;
	canFilter1.FilterIdHigh = 0x000  << 5;

	canFilter1.FilterMaskIdLow = 0x000 << 5;
	canFilter1.FilterIdLow = 0x000  << 5;

	canFilter1.FilterMode = CAN_FILTERMODE_IDMASK;
	canFilter1.FilterScale = CAN_FILTERSCALE_16BIT;
	canFilter1.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	canFilter1.FilterBank = 0;
	canFilter1.FilterActivation = ENABLE;

	HAL_CAN_ConfigFilter(&hcan1, &canFilter1);
	HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
	HAL_CAN_Start(&hcan1);	//CAN START
}

void CAN_TX(unsigned char* txchar)
{
	/////CAN �۽Ž� ������ ���� ������////
	canTxHeader.StdId = 0x102;
	canTxHeader.RTR = CAN_RTR_DATA;
	canTxHeader.IDE = CAN_ID_STD;
	canTxHeader.DLC = 8;
	//////////////////////////////

	TxMailBox = HAL_CAN_GetTxMailboxesFreeLevel(&hcan1);
	HAL_CAN_AddTxMessage(&hcan1, &canTxHeader, txchar, &TxMailBox);
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)	//CAN RX Interrupt
{

	if(hcan->Instance == CAN1)
	{
		HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &canRxHeader, &can1Rx0Data[0]);
		if(canbypass2uart == 1)	printf("%s\r\n",&can1Rx0Data[0]);

		gval_can_rxc_flag = ON;
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	static unsigned char bStarted1 = 0;
	static unsigned char rx_buffer1[uart1rxbuffersize];
	static unsigned char rx_rd_index1 = 0;

	static unsigned char bStarted2 = 0;
	static unsigned char rx_buffer2[uart2rxbuffersize];
	static unsigned char rx_rd_index2 = 0;

	//UART RX Interrup Service Routine
	if(huart->Instance == USART1)
	{
		HAL_UART_Receive_IT(&huart1, &rx1_data,1);

		//printf("%c",rx1_data);

		if(g_bReceived1 == OFF)	//수신데이터 처리전 수신된 데이터는 무시
		{
			switch(rx1_data)
			{
				case '(' :
					bStarted1 = ON;
					rx_rd_index1 = 0;
					break;

				case ')' :
					if(bStarted1 == OFF) break;

					memset(g_strData1, 0x00, uart1rxbuffersize);
					strncpy(g_strData1, rx_buffer1, rx_rd_index1);

					bStarted1 = OFF;
					g_bReceived1	= ON;

					break;

				default :
					if(bStarted1)
						{
							rx_buffer1[rx_rd_index1++] = rx1_data;
						}
					break;

				// buffer overflow
				if(rx_rd_index1 >= uart1rxbuffersize)
				{
					bStarted1 = OFF;
					rx_rd_index1 = 0;
				}
			}
		}
		//End of RX Interrup Service Routine
	}
	if(huart->Instance == USART2)
	{
		HAL_UART_Receive_IT(&huart2, &rx2_data,1);

		if(g_bReceived2 == OFF)	//수신데이터 처리전 수신된 데이터는 무시
		{
			switch(rx2_data)
			{
				case '(' :
					bStarted2 = ON;
					rx_rd_index2 = 0;
					break;

				case ')' :
					if(bStarted2 == OFF) break;

					memset(g_strData2, 0x00, uart2rxbuffersize);
					strncpy(g_strData2, rx_buffer2, rx_rd_index2);

					bStarted2 = OFF;
					g_bReceived2	= ON;

					break;

				default :
					if(bStarted2)
						{
							rx_buffer2[rx_rd_index2++] = rx2_data;
						}
					break;

				// buffer overflow
				if(rx_rd_index2 >= uart2rxbuffersize)
				{
					bStarted2 = OFF;
					rx_rd_index2 = 0;
				}
			}
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////
/* End Code ---------------------------------------------------------*/
