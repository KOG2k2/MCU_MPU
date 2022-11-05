/*
 * global.c
 *
 *  Created on: Nov 3, 2022
 *      Author: Admin
 */

#include "global.h"

int mode = 0;

//MODE 1
int west_traffic = 0;
int north_traffic = 0;
int seg_disp = 0;
int mode_change = 0;

//MODE 2
int Stat_M2_1 = 0;
int Stat_M2_2 = 0;
int Stat_M2_3 = 0;

//MODE 3
int Stat_M3_1 = 0;
int Stat_M3_2 = 0;
int Stat_M3_3 = 0;

//MODE 4
int Stat_M4_1 = 0;
int Stat_M4_2 = 0;
int Stat_M4_3 = 0;

//For HAL delay//
int AUTO_RED = 0;
int AUTO_YELLOW = 0;
int AUTO_GREEN = 0;

int counterRED_WEST = 0;
int counterGREEN_WEST = 0;
int counterYELLOW_WEST = 0;

int counterRED_NORTH = 0;
int counterGREEN_NORTH = 0;
int counterYELLOW_NORTH = 0;

void LedTimeInit(){
	AUTO_RED = 5;
	AUTO_YELLOW = 2;
	AUTO_GREEN = 3;
}

void Setup(){
	mode = MODE1;

	west_traffic = INIT;
	north_traffic = INIT;
	seg_disp = INIT;
	mode_change = INIT;

	Stat_M2_1 = INIT;
	Stat_M2_2 = INIT;
	Stat_M2_3 = INIT;

	Stat_M3_1 = INIT;
	Stat_M3_2 = INIT;
	Stat_M3_3 = INIT;

	Stat_M4_1 = INIT;
	Stat_M4_2 = INIT;
	Stat_M4_3 = INIT;

	counterRED_WEST = AUTO_RED;
	counterGREEN_WEST = AUTO_GREEN;
	counterYELLOW_WEST = AUTO_YELLOW;

	counterRED_NORTH = AUTO_RED;
	counterGREEN_NORTH = AUTO_GREEN;
	counterYELLOW_NORTH = AUTO_YELLOW;
}
/*-------------------------------------*/
