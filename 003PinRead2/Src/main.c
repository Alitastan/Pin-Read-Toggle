/**
  ******************************************************************************
  * @file    main.c
  * @author  Auto-generated by STM32CubeIDE
  * @version V1.0
  * @brief   Default main function.
  ******************************************************************************
*/

#include <stdint.h>
#include "main.h"

void delay_func(uint32_t volatile delay);


int main(void)
{
	/*
	uint32_t volatile *pClkctrlreg = (uint32_t*)0x5800004C;
	uint32_t volatile *pPortBmodereg = (uint32_t*)0x48000400;
	uint32_t volatile *pPortBoutreg = (uint32_t*)0x48000414;
	uint32_t volatile *pPortAmodereg = (uint32_t*)0x48000000;
	uint32_t volatile *pPortAinreg = (uint32_t*)0x48000010; */

	RCC_AHB2ENR_t volatile *const pClkctrlreg = (RCC_AHB2ENR_t*)0x5800004C;
	GPIOx_MODER_t volatile *const pPortAmodereg = (GPIOx_MODER_t*)0x48000000;
	GPIOx_MODER_t volatile *const pPortBmodereg = (GPIOx_MODER_t*)0x48000400;
	GPIOx_IDR_t volatile *const pPortAinreg = (GPIOx_IDR_t*)0x48000010;
	GPIOx_ODR_t volatile *const pPortBoutreg = (GPIOx_ODR_t*)0x48000414;

	// 1. Enable the clock for GPIOB / GPIOA peripheral in the AHB2ENR
	pClkctrlreg->gpiob_en = 0x1;
	pClkctrlreg->gpioa_en = 0x1;
	//*pClkctrlreg |= (3 << 0);


	// 2. Configure the 3 Port B pins as output
	/*
	//a. Clear 11th, 10th, 1st and 0th bits
	*pPortBmodereg &= ~(3 << 10);
	*pPortBmodereg &= ~(3 << 0);
	*pPortBmodereg &= ~(3 << 2);

	//b. Set 10th bit to 1
	*pPortBmodereg |= (1 << 10);
	//b. Set 0th bit to 1
	*pPortBmodereg |= (1 << 0);
	//b. Set 1st bit to 1
	*pPortBmodereg |= (1 << 2); */

	pPortBmodereg->mode0 = 0x01;
	pPortBmodereg->mode1 = 0x01;
	pPortBmodereg->mode5 = 0x01;

	// Configuring PA12 GPIO pin as input
	//*pPortAmodereg &= ~(3 << 25);
	pPortAmodereg->mode12 = 0;


	while(1){
		//Read the pin status of the pin PA12 (GPIO INPUT DATA REGISTER)
		//uint16_t pin_status = (uint16_t)*pPortAinreg & (1 << 12); // zero out all the bits except bit 12
		pPortAinreg->id12 = 1;

		if(pPortAinreg->id12){
			//toggle the LED faster
			pPortBoutreg->od5 = 1;
			delay_func(100000);
			pPortBoutreg->od5 = 0;
			delay_func(100000);
			pPortBoutreg->od0 = 1;
			delay_func(100000);
			pPortBoutreg->od0 = 0;
			delay_func(100000);
			pPortBoutreg->od1 = 1;
			delay_func(100000);
			pPortBoutreg->od1 = 0;
			delay_func(100000);
			/**pPortBoutreg |= (1 << 5);
			delay_func(100000);
			*pPortBoutreg &= ~(1 << 5);
			delay_func(100000);
			*pPortBoutreg |= (1 << 0);
			delay_func(100000);
			*pPortBoutreg &= ~(1 << 0);
			delay_func(100000);
			*pPortBoutreg |= (1 << 1);
			delay_func(100000);
			*pPortBoutreg &= ~(1 << 1);
			delay_func(100000);*/
		}else{
			//toggle the LED slower
			pPortBoutreg->od5 = 1;
			delay_func(200000);
			pPortBoutreg->od5 = 0;
			delay_func(200000);
			pPortBoutreg->od0 = 1;
			delay_func(200000);
			pPortBoutreg->od0 = 0;
			delay_func(200000);
			pPortBoutreg->od1 = 1;
			delay_func(200000);
			pPortBoutreg->od1 = 0;
			delay_func(200000);
			/*
			*pPortBoutreg |= (1 << 5);
			delay_func(200000);
			*pPortBoutreg &= ~(1 << 5);
			delay_func(200000);
			*pPortBoutreg |= (1 << 0);
			delay_func(200000);
			*pPortBoutreg &= ~(1 << 0);
			delay_func(200000);
			*pPortBoutreg |= (1 << 1);
			delay_func(200000);
			*pPortBoutreg &= ~(1 << 1);
			delay_func(200000);*/
		}
	}

		// Small human observable software delay

		//for(uint32_t delay = 0 ; delay < 10000 ; delay++);



	//for(;;);
}

// Small human observable software delay

void delay_func(uint32_t volatile delay){
	for(uint32_t i = 0 ; i < delay ; i++ );
}

