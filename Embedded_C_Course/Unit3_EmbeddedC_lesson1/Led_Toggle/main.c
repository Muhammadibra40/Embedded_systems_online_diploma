/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "Platform_Types.h"

#define RCC_REG           0x40021000
#define GPIO_Port_A       0x40010800

#define RCC_APB2ENR       *(vuint32 *)(RCC_REG + 0x18)
#define GPIO_Port_A_CRH   *(vuint32 *)(GPIO_Port_A + 0x04)
#define GPIO_Port_A_ODR   *(vuint32 *)(GPIO_Port_A + 0x0C)

typedef union
{
	vuint32     all_Bits;
	struct
	{
		vuint32 reserved:13;
		vuint32 pin13:1;
	}pins;
}ODR_REG_t;

volatile ODR_REG_t* ODR_REG = (volatile ODR_REG_t *)(GPIO_Port_A + 0x0C);

int main(void)
{
	RCC_APB2ENR |= (1 << 2);
	GPIO_Port_A_CRH &= 0xFF0FFFFF;
	GPIO_Port_A_CRH |= 0x00200000;

	while(1)
	{
		ODR_REG -> pins.pin13 = 1;
		for(int i = 0; i < 5000; i++);
		ODR_REG -> pins.pin13 = 0;
		for(int i = 0; i < 5000; i++);
	}
    return 0;
}
