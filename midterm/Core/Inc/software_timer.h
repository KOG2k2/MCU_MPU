/*
 * software_timer.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Admin
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#define COUNT_RESET 0

#define FLAG_ON 1
#define FLAG_OFF 0

extern int LEDtimer_flag;
extern int SEG7timer_flag;
extern int LONGtimer_flag;

void setLEDTimer(int duration);
void setSEG7Timer(int duration);
void setLONGTimer(int duration);

void timerRun();

#endif /* INC_SOFTWARE_TIMER_H_ */
