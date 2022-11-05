/*
 * fsm_auto.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#include "fsm_auto.h"

enum state mode = INIT;

int counter = COUNTER;

void fsm_simple_buttons_run (){
	if(LEDtimer_flag == FLAG_ON){
		TOGGLE();
		setLEDTimer(ONE_SEC);
	}

	switch(mode){
	case INIT:
		mode = NORM_STATE;
		setLEDTimer(REV_TIMER_UP); //LED
		setSEG7Timer(REV_TIMER_UP); //SEG7
		setLONGTimer(REV_TIMER_UP); //Long pressed but do nothing
		break;

	case NORM_STATE:
		if(isButtonPressed(RES_BUTTON)){
			mode = RES_STATE;
			counter = END_COUNT;
			setLONGTimer(TEN_SEC);
			display7SEG1(counter);
		}

		if(isButtonPressed(INC_BUTTON)){
			mode = INC_STATE;
			counter++;
			if(counter > COUNTER) counter = END_COUNT;
			setLONGTimer(TEN_SEC);
			display7SEG1(counter);
		}

		if(isButtonPressed(DEC_BUTTON)){
			mode = DEC_STATE;
			counter--;
			if(counter < END_COUNT) counter = COUNTER;
			setLONGTimer(TEN_SEC);
			display7SEG1(counter);
		}

		if(SEG7timer_flag == FLAG_ON){
			display7SEG1(counter);
			if(counter > END_COUNT) counter--;
			setSEG7Timer(ONE_SEC);
		}
		break;
	case RES_STATE:
		if(isButtonPressed(RES_BUTTON)){
			counter = END_COUNT;
			setLONGTimer(TEN_SEC);
			display7SEG1(counter);
		}

		if(isButtonPressed(INC_BUTTON)){
			mode = INC_STATE;
			counter++;
			if(counter > COUNTER) counter = END_COUNT;
			setLONGTimer(TEN_SEC);
			display7SEG1(counter);
		}

		if(isButtonPressed(DEC_BUTTON)){
			mode = DEC_STATE;
			counter--;
			if(counter < END_COUNT) counter = COUNTER;
			setLONGTimer(TEN_SEC);
			display7SEG1(counter);
		}

		if(LONGtimer_flag == FLAG_ON){
			mode = NORMAL_STATE;
			setLONGTimer(TEN_SEC);
		}
		break;
	case INC_STATE:
		if(isButtonPressed(INC_BUTTON)){
			counter++;
			if(counter > COUNTER) counter = END_COUNT;
			setLONGTimer(TEN_SEC);
			display7SEG1(counter);
		}

		if(isButtonPressed(RES_BUTTON)){
			mode = RES_STATE;
			counter = END_COUNT;
			setLONGTimer(TEN_SEC);
			display7SEG1(counter);
		}

		if(isButtonPressed(DEC_BUTTON)){
			mode = DEC_STATE;
			counter--;
			if(counter < END_COUNT) counter = COUNTER;
			setLONGTimer(TEN_SEC);
			display7SEG1(counter);
		}

		if(isLongButtonPressed(INC_BUTTON)){
			counter++;
			if(counter > COUNTER) counter = END_COUNT;
			display7SEG1(counter);
			setLONGTimer(TEN_SEC);
		}

		if(LONGtimer_flag == FLAG_ON){
			mode = NORMAL_STATE;
			setSEG7Timer(TEN_SEC);
		}
		break;
	case DEC_STATE:
		if(isButtonPressed(RES_BUTTON)){
			mode = RES_STATE;
			counter = END_COUNT;
			setLONGTimer(TEN_SEC);
			display7SEG1(counter);
		}

		if(isButtonPressed(INC_BUTTON)){
			mode = INC_STATE;
			counter++;
			if(counter > COUNTER) counter = END_COUNT;
			setLONGTimer(TEN_SEC);
			display7SEG1(counter);
		}

		if(isButtonPressed(DEC_BUTTON)){
			counter--;
			if(counter < END_COUNT) counter = COUNTER;
			setLONGTimer(TEN_SEC);
			display7SEG1(counter);
		}

		if(isLongButtonPressed(DEC_BUTTON)){
			counter--;
			if(counter > COUNTER) counter = END_COUNT;
			display7SEG1(counter);
			setLONGTimer(TEN_SEC);
		}

		if(LONGtimer_flag == FLAG_ON){
			mode = NORMAL_STATE;
			setLONGTimer(TEN_SEC);
		}
		break;
	}
}
