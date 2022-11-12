/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#include "button.h"

int BUTTONS[NUM_OF_BUTTON] = {RES_Pin, INC_Pin, DEC_Pin};

int KeyReg0[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg3[NUM_OF_BUTTON] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int INTERVAL = 100;
int TimeOutForKeyPress[NUM_OF_BUTTON] =  {0, 0, 0};

int button_flag[NUM_OF_BUTTON] = {0, 0, 0};
int long_flag[NUM_OF_BUTTON] = {0, 0, 0};

int isButtonPressed(int index){
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

int isLongButtonPressed(int index){
	if(long_flag[index] == 1){
		long_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index){
	button_flag[index] = 1;
}

void longSubKeyProcess(int index){
	long_flag[index] = 1;
}

void getKeyInput(){
  for(int index = 0; index < NUM_OF_BUTTON; index++){
  KeyReg2[index] = KeyReg1[index];
  KeyReg1[index] = KeyReg0[index];
  KeyReg0[index] = HAL_GPIO_ReadPin(GPIOA,BUTTONS[index]);
  if ((KeyReg1[index] == KeyReg0[index]) && (KeyReg1[index] == KeyReg2[index])){
	  if (KeyReg2[index] != KeyReg3[index]){
		  KeyReg3[index] = KeyReg2[index];

		  if (KeyReg3[index] == PRESSED_STATE){
			  TimeOutForKeyPress[index] = BUTTON_HOLD_TIME;
			  subKeyProcess(index);
		  }
	  }else{
		  TimeOutForKeyPress[index]--;
		  if (TimeOutForKeyPress[index] == 0 && KeyReg3[index] == PRESSED_STATE) {
			  longSubKeyProcess(index);
			  TimeOutForKeyPress[index] = INTERVAL;
		  }
		}
	}
  }
}
