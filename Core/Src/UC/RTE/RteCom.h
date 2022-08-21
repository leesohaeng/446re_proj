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
#include "can.h"
#include "usart.h"

/* Macro -------------------------------------------------------------*/
#define ON	1
#define OFF	0

#define uart1rxbuffersize 50
#define uart2rxbuffersize 50
/* Func & Typedef -----------------------------------------------------------*/
void CAN_INIT(void);											//CAN Init
void CAN_TX(unsigned char* txchar);								//CAN Tx Routine
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);	//CAN RX Interrupt
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
//int __io_putchar(int ch);

/* Variables ---------------------------------------------------------*/
unsigned char rx1_data;
uint8_t g_strData1[uart1rxbuffersize];			//UART1 수신완료된 데이터 저장
uint8_t g_bReceived1;

unsigned char rx2_data;
uint8_t g_strData2[uart2rxbuffersize];			//UART3 수신완료된 데이터 저장
uint8_t g_bReceived2;

uint8_t can1Tx0Data[8];
uint8_t can1Rx0Data[8];
CAN_FilterTypeDef canFilter1;
CAN_RxHeaderTypeDef canRxHeader;
CAN_TxHeaderTypeDef canTxHeader;
uint32_t TxMailBox;
uint8_t	canbypass2uart;
volatile uint8_t gval_can_rxc_flag;
/* Code here ---------------------------------------------------------*/

/* End Code ---------------------------------------------------------*/
