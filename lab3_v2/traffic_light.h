/*
 * traffic_light.h
 *
 *  Created on: Sep 29, 2021
 *      Author: ngocc
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#define NO_OF_ROAD 2
enum State_Traffic_Light{RED, AMBER, GREEN};

//initialization is inside traffic_light.c
extern int time_traffic_light[NO_OF_ROAD];
extern enum State_Traffic_Light state_traffic_light[NO_OF_ROAD];

//this function will be called every 1 second.
void run_traffic_light();
void update_time_traffic_light();
void display_traffic_light();

#endif /* INC_TRAFFIC_LIGHT_H_ */
