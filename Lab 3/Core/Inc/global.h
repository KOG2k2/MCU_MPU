/*
 * global.h
 *
 *  Created on: Nov 3, 2022
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "led_disp.h"

#define INIT 0

#define NUM_OF_BUTTON 3
#define BUTTON1 0
#define BUTTON2 1
#define BUTTON3 2

#define MAX_COUNT 99
#define MIN_COUNT 1

#define RED_ON 1
#define GREEN_ON 2
#define YELLOW_ON 3

#define MODE1 1
#define MODE2 2
#define MODE3 3
#define MODE4 4

#define BLINK 1

#define INCREASE 1
#define SAVE 2

#define SEG1 1
#define SEG2 2

extern int mode;

extern int west_traffic;
extern int north_traffic;
extern int seg_disp;
extern int mode_change;

extern int Stat_M2_1;
extern int Stat_M2_2;
extern int Stat_M2_3;

extern int Stat_M3_1;
extern int Stat_M3_2;
extern int Stat_M3_3;

extern int Stat_M4_1;
extern int Stat_M4_2;
extern int Stat_M4_3;

extern int temp_RED;
extern int temp_YELLOW;
extern int temp_GREEN;
extern int AUTO_RED;
extern int AUTO_YELLOW;
extern int AUTO_GREEN;

extern int counterRED_WEST;
extern int counterYELLOW_WEST;
extern int counterGREEN_WEST;

extern int counterRED_NORTH;
extern int counterYELLOW_NORTH;
extern int counterGREEN_NORTH;

void LedTimeInit();
void Setup();

#endif /* INC_GLOBAL_H_ */
