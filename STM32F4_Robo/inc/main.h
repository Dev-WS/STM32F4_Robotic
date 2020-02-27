
#ifndef MAIN_H
#define MAIN_H


#include <string.h>
#include <test.h>
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "ssd1306.h"
#include "horse_anim.h"


void SystemClock_Config(void);
void Error_Handler(void);
void HAL_TIM_MspPostInit(TIM_HandleTypeDef* timHandle);
void TIM1_Init();


void send_string(char* s);
void receive_string(uint8_t* x);
void hardware_init();


UART_HandleTypeDef uart;
SPI_HandleTypeDef hspi2;
I2C_HandleTypeDef hi2c1;
TIM_HandleTypeDef htim1;
GPIO_InitTypeDef gpio;



#endif
