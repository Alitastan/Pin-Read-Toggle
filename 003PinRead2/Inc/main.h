

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>

// Clock control register for AHB2 peripheral
typedef struct{
	uint32_t gpioa_en:1;
	uint32_t gpiob_en:1;
	uint32_t gpioc_en:1;
	uint32_t reserved:1;
	uint32_t gpioe_en:1;
	uint32_t reserved1:2;
	uint32_t gpioh_en:1;
	uint32_t reserved2:24;
}RCC_AHB2ENR_t;

// GPIO mode registers
typedef struct{
	uint32_t mode0:2;
	uint32_t mode1:2;
	uint32_t mode2:2;
	uint32_t mode3:2;
	uint32_t mode4:2;
	uint32_t mode5:2;
	uint32_t mode6:2;
	uint32_t mode7:2;
	uint32_t mode8:2;
	uint32_t mode9:2;
	uint32_t mode10:2;
	uint32_t mode11:2;
	uint32_t mode12:2;
	uint32_t mode13:2;
	uint32_t mode14:2;
	uint32_t mode15:2;
}GPIOx_MODER_t;

//GPIO output data registers
typedef struct{
	uint32_t od0:1;
	uint32_t od1:1;
	uint32_t od2:1;
	uint32_t od3:1;
	uint32_t od4:1;
	uint32_t od5:1;
	uint32_t od6:1;
	uint32_t od7:1;
	uint32_t od8:1;
	uint32_t od9:1;
	uint32_t od10:1;
	uint32_t od11:1;
	uint32_t od12:1;
	uint32_t od13:1;
	uint32_t od14:1;
	uint32_t od15:1;
	uint32_t reserved:16;

}GPIOx_ODR_t;

//GPIO input data registers
typedef struct{
	uint32_t id0:1;
	uint32_t id1:1;
	uint32_t id2:1;
	uint32_t id3:1;
	uint32_t id4:1;
	uint32_t id5:1;
	uint32_t id6:1;
	uint32_t id7:1;
	uint32_t id8:1;
	uint32_t id9:1;
	uint32_t id10:1;
	uint32_t id11:1;
	uint32_t id12:1;
	uint32_t id13:1;
	uint32_t id14:1;
	uint32_t id15:1;
	uint32_t reserved:16;
}GPIOx_IDR_t;

#endif /* MAIN_H_ */
