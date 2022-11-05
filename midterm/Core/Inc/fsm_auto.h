/*
 * fsm_auto.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#ifndef INC_FSM_AUTO_H_
#define INC_FSM_AUTO_H_

#include "main.h"
#include "software_timer.h"
#include "led_disp.h"
#include "button.h"

#define TEN_SEC 1000
#define ONE_SEC 100
#define REV_TIMER_UP 10

#define COUNTER 9

#define END_COUNT 0

enum state {INIT, NORM_STATE, RES_STATE, INC_STATE, DEC_STATE};
extern enum state mode;

extern int counter;

void fsm_simple_buttons_run ();

#endif /* INC_FSM_AUTO_H_ */
