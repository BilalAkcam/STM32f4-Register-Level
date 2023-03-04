#include "uart_driver.h"

UART_HandleTypeDef UartHandle;


void UART_Init()
{
	
  GPIO_InitTypeDef  GPIO_InitStruct;
  

  __HAL_RCC_GPIOA_CLK_ENABLE();


  __HAL_RCC_USART2_CLK_ENABLE(); 
  
  GPIO_InitStruct.Pin       = GPIO_PIN_2;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF1_USART2;
  
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
    
  GPIO_InitStruct.Pin 		= GPIO_PIN_3;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_NOPULL;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF1_USART2;

  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	
    

  UartHandle.Instance        = USART2;
	
  UartHandle.Init.BaudRate   = 9600;
  UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
  UartHandle.Init.StopBits   = UART_STOPBITS_1;
  UartHandle.Init.Parity     = UART_PARITY_NONE;
  UartHandle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
  UartHandle.Init.Mode       = UART_MODE_TX_RX;	
  UartHandle.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
	
  HAL_UART_Init(&UartHandle);
}



