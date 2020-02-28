
#ifndef MAIN_H
#define MAIN_H


#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "ssd1306.h"
#include "horse_anim.h"
#include <string.h>
#include <test.h>


void SystemClock_Config(void);
void Error_Handler(void);
void HAL_TIM_MspPostInit(TIM_HandleTypeDef* timHandle);
void TIM1_Init();
void send_string(char* s);
void receive_string(uint8_t* x);


void hardware_init();

#endif
