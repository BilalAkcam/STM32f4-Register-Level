#include "button_driver.h"
#include "stm32f0xx_hal.h"
#include "uart_driver.h"


#define BUFFER_SIZE 256

UART_HandleTypeDef UartHandle;

uint32_t rx_data = 0;
volatile uint8_t data_buffer[10];
volatile uint32_t data_flag = 0;
uint32_t cnt = 0;


static void UART_Error_Handler(void);


/*  
  UART_Init() belirtilen hiz ve ayarlarla UART'ı baslatir ve RX kesmesini aktif hale getirir.

*/
void UART_Init(void)
{
	
GPIO_InitTypeDef  GPIO_InitStruct;
  
  __HAL_RCC_GPIOA_CLK_ENABLE();

  __HAL_RCC_USART2_CLK_ENABLE(); 
  
	
	
  GPIO_InitStruct.Pin       = GPIO_PIN_2;
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
  GPIO_InitStruct.Speed     = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF1_USART2;
  
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
    
  /* UART RX GPIO pin configuration  */
  GPIO_InitStruct.Pin = GPIO_PIN_3;
	
  GPIO_InitStruct.Mode      = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull      = GPIO_PULLUP;
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
	
	
  if(HAL_UART_Init(&UartHandle) != HAL_OK)
  {
		
    UART_Error_Handler();
  }
	
   SET_BIT(USART2->CR1, USART_CR1_RXNEIE);

	
	
  HAL_NVIC_SetPriority(USART2_IRQn, 0, 1);
  HAL_NVIC_EnableIRQ(USART2_IRQn);
}





static void UART_Error_Handler(void)
{
     while(1)
    {      
  
    }
}



void USART2_IRQHandler(void) {
	uint32_t isrflags = USART2->ISR;
	uint32_t control_reg1 = USART2->CR1;

	/* UART in mode Receiver */
	if (((isrflags & USART_ISR_RXNE) != RESET) && ((control_reg1 & USART_CR1_RXNEIE) != RESET)) {
		data_buffer[cnt++] = (uint8_t) USART2->RDR;
		if (cnt == 6) {
			cnt = 0;
			data_flag = 1;
		}
		return;
	}

	if (((isrflags & USART_ISR_TXE) != RESET) && ((control_reg1 & USART_CR1_TXEIE) != RESET)) {

		return;
	}
}

