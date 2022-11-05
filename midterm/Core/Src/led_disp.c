/*
 * led_disp.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#include "led_disp.h"

void TOGGLE(){
	HAL_GPIO_TogglePin(RED_GPIO_Port, RED_Pin);
}

const uint8_t SEG7[10] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};

void display7SEG1(int num){
	HAL_GPIO_WritePin(a_GPIO_Port, a_Pin, ((SEG7[num]>>0)&0x01));
	HAL_GPIO_WritePin(b_GPIO_Port, b_Pin, ((SEG7[num]>>1)&0x01));
	HAL_GPIO_WritePin(c_GPIO_Port, c_Pin, ((SEG7[num]>>2)&0x01));
	HAL_GPIO_WritePin(d_GPIO_Port, d_Pin, ((SEG7[num]>>3)&0x01));
	HAL_GPIO_WritePin(e_GPIO_Port, e_Pin, ((SEG7[num]>>4)&0x01));
	HAL_GPIO_WritePin(f_GPIO_Port, f_Pin, ((SEG7[num]>>5)&0x01));
	HAL_GPIO_WritePin(g_GPIO_Port, g_Pin, ((SEG7[num]>>6)&0x01));
}
