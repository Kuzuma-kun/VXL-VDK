/*
 * traffic_light.h
 *
 *  Created on: Sep 29, 2021
 *      Author: ngocc
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "7_seg_display.h"
#include "main.h"
//this traffic light has it own timer for 1 second count.
#include "timer.h"

#define NO_OF_ROAD 2
enum State_Traffic_Light{RED, AMBER, GREEN};

//initialization is inside traffic_light.c
extern int time_traffic_light[NO_OF_ROAD];
extern enum State_Traffic_Light state_traffic_light[NO_OF_ROAD];


extern int red_duration;
extern int amber_duration;
extern int green_duration;

void init_traffic_light();
//this function will be called every 1 second.
void run_traffic_light();
void run_traffic_light_timer();
void update_time_traffic_light();
void display_traffic_light();

void toggleRedLight();
void toggleAmberLight();
void toggleGreenLight();

#endif /* INC_TRAFFIC_LIGHT_H_ */
