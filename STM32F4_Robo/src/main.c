/**
  ******************************************************************************
  * @file    main.c
  * @author  Dev-WS
  *
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "ssd1306.h"
#include "horse_anim.h"
#include <string.h>
#include <test.h>

UART_HandleTypeDef uart;
SPI_HandleTypeDef hspi2;
I2C_HandleTypeDef hi2c1;
TIM_HandleTypeDef htim1;
GPIO_InitTypeDef gpio;

void send_string(char* s)
{
	HAL_UART_Transmit(&uart, (uint8_t*)s, strlen(s), 1000);
}

void receive_string(uint8_t* x){
	HAL_UART_Receive(&uart, x, sizeof(*x), 1000);
}

void SystemClock_Config(void);
//void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

void hardware_init(){

	gpio.Mode = GPIO_MODE_AF_PP;
	gpio.Pin = GPIO_PIN_2;
	gpio.Alternate = GPIO_AF7_USART2;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &gpio);

	gpio.Mode = GPIO_MODE_AF_OD;
	gpio.Pin = GPIO_PIN_3;
	HAL_GPIO_Init(GPIOA, &gpio);

	gpio.Pin = GPIO_PIN_8 |GPIO_PIN_9;
	gpio.Mode = GPIO_MODE_AF_OD;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_HIGH;
	gpio.Alternate = GPIO_AF4_I2C1;
	HAL_GPIO_Init(GPIOB, &gpio);

	uart.Instance = USART2;
	uart.Init.BaudRate = 115200;
	uart.Init.WordLength = UART_WORDLENGTH_8B;
	uart.Init.Parity = UART_PARITY_NONE;
	uart.Init.StopBits = UART_STOPBITS_1;
	uart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	uart.Init.OverSampling = UART_OVERSAMPLING_16;
	uart.Init.Mode = UART_MODE_TX_RX;
	HAL_UART_Init(&uart);

	hi2c1.Instance = I2C1;
	hi2c1.Init.ClockSpeed = 400000;
	hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
	hi2c1.Init.OwnAddress1 = 0;
	hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	hi2c1.Init.OwnAddress2 = 0;
	hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	HAL_I2C_Init(&hi2c1);


}

void HAL_TIM_MspPostInit(TIM_HandleTypeDef* timHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct;
  if(timHandle->Instance==TIM1)
  {
		GPIO_InitStruct.Pin =  GPIO_PIN_5;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_NOPULL;
		HAL_GPIO_Init(GPIOA,&GPIO_InitStruct);

  }

}

void TIM1_Init(){

	  TIM_ClockConfigTypeDef sClockSourceConfig;
	  TIM_MasterConfigTypeDef sMasterConfig;
	  TIM_OC_InitTypeDef sConfigOC;
	  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig;

	  htim1.Instance = TIM1;
	  htim1.Init.Prescaler = 999;
	  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
	  htim1.Init.Period = 4096;
	  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	  htim1.Init.RepetitionCounter = 0;
	  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
	  {
	    Error_Handler();
	  }

	  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
	    if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
	    {
	      Error_Handler();
	    }

	    if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
	    {
	      Error_Handler();
	    }

	    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
	    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
	    if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
	    {
	      Error_Handler();
	    }

	    sConfigOC.OCMode = TIM_OCMODE_PWM1;
	    sConfigOC.Pulse = 1000;
	    sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	    sConfigOC.OCNPolarity = TIM_OCNPOLARITY_LOW;
	    sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	    sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
	    sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
	    if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
	    {
	      Error_Handler();
	    }

	    sConfigOC.Pulse = 500;
	    if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_2) != HAL_OK)
	    {
	      Error_Handler();
	    }

	    sConfigOC.Pulse = 3000;
	    if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
	    {
	      Error_Handler();
	    }

	    sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
	    sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
	    sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
	    sBreakDeadTimeConfig.DeadTime = 10;
	    sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
	    sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_LOW;
	    sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_ENABLE;
	    if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
	    {
	      Error_Handler();
	    }

	    HAL_TIM_MspPostInit(&htim1);
	    //HAL_TIM_Base_MspDeInit(&htim1);
	    //HAL_TIM_Base_MspInit(&htim1);
}


int main(void)
{
	HAL_Init();

	int n = 0;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_USART2_CLK_ENABLE();
	//__HAL_RCC_SPI2_CLK_ENABLE();
	__HAL_RCC_I2C1_CLK_ENABLE();
	__HAL_RCC_PWR_CLK_ENABLE();
	SystemClock_Config();

	hardware_init();
	TIM1_Init();

	//uint8_t res = ssd1306_Init();
	//printf("OLED init: %d\n", res);
	SSD1306_Init();
	SSD1306_GotoXY(10,27);
	SSD1306_Puts("WLODEK", &Font_7x10, 1);
	SSD1306_GotoXY(10,52);
	SSD1306_Puts("Test.", &Font_7x10, 1);
	SSD1306_UpdateScreen(); //display
	SSD1306_Fill(0x01);
	HAL_Delay(1000);


	HAL_TIM_Base_Start(&htim1);
	HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_ALL);
	HAL_TIMEx_PWMN_Start(&htim1,TIM_CHANNEL_ALL);
//	ssd1306_Fill(Black);


	while (1)
		{
			if (n == 0) send_string("Hello world!\r\n");
			else send_string("Hello world 2222!\r\n");
			n++;
			if (n > 1) n = 0;

			//uint8_t test;
			uint8_t buffer;
			//receive_string(buffer);
			if (__HAL_UART_GET_FLAG(&uart, UART_FLAG_RXNE) == SET){

			//receive_string(&buffer);

			//HAL_UART_Receive(&uart, &buffer, sizeof(buffer), 1000);
	//		switch (buffer){
	//		case 'a':
	//		send_string("AA\r\n");
	//		break;
	//		}
			//send_string(&buffer);
			//send_string("\r\n");
			}

				  SSD1306_Clear();
				  SSD1306_DrawBitmap(0,0,horse1,128,64,1);
				  SSD1306_UpdateScreen();

				  SSD1306_Clear();
				  SSD1306_DrawBitmap(0,0,horse2,128,64,1);
				  SSD1306_UpdateScreen();

				  SSD1306_Clear();
				  SSD1306_DrawBitmap(0,0,horse3,128,64,1);
				  SSD1306_UpdateScreen();

				  SSD1306_Clear();
				  SSD1306_DrawBitmap(0,0,horse4,128,64,1);
				  SSD1306_UpdateScreen();

				  SSD1306_Clear();
				  SSD1306_DrawBitmap(0,0,horse5,128,64,1);
				  SSD1306_UpdateScreen();

				  SSD1306_Clear();
				  SSD1306_DrawBitmap(0,0,horse6,128,64,1);
				  SSD1306_UpdateScreen();


				  SSD1306_Clear();
				  SSD1306_DrawBitmap(0,0,horse7,128,64,1);
				  SSD1306_UpdateScreen();

				  SSD1306_Clear();
				  SSD1306_DrawBitmap(0,0,horse8,128,64,1);
				  SSD1306_UpdateScreen();


				  SSD1306_Clear();
				  SSD1306_DrawBitmap(0,0,horse9,128,64,1);
				  SSD1306_UpdateScreen();


				  SSD1306_Clear();
				  SSD1306_DrawBitmap(0,0,horse10,128,64,1);
				  SSD1306_UpdateScreen();

			//HAL_Delay(10);
		}

	return 0;
}

void SystemClock_Config(void){

	  RCC_OscInitTypeDef RCC_OscInitStruct;
	  RCC_ClkInitTypeDef RCC_ClkInitStruct;

	  __HAL_RCC_PWR_CLK_ENABLE();

	  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
	  RCC_OscInitStruct.PLL.PLLM = 4;
	  RCC_OscInitStruct.PLL.PLLN = 168;
	  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	  RCC_OscInitStruct.PLL.PLLQ = 4;
	  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
	  {
	    Error_Handler();
	  }


	  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
	                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
	  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
	  {
	    Error_Handler();
	  }


	    /**Configure the Systick interrupt time
	    */
	  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

	    /**Configure the Systick
	    */
	  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

	  /* SysTick_IRQn interrupt configuration */
	  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}


void Error_Handler(void)
{
  while(1)
  {
  }
}



