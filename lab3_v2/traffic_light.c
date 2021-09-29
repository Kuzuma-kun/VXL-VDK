/*
 * traffic_light.c
 *
 *  Created on: Sep 29, 2021
 *      Author: ngocc
 */

#include "traffic_light.h"
#include "7_seg_display.h"
#include "main.h"
#define NO_OF_ROAD 2

#define RED_DURATION 5
#define AMBER_DURATION 2
#define GREEN_DURATION 3
//khong the su dung ~TRAFFIC_LIGHT_ENABLE duoc. no =/= GPIO_PIN_RESET
#define TRAFFIC_LIGHT_ENABLE 	GPIO_PIN_SET
#define TRAFFIC_LIGHT_DISABLE	GPIO_PIN_RESET
#define PORT_TRAFFIC_LIGHT		GPIOA
int red_duration = 5;
int amber_duration = 2;
int green_duration = 3;

int time_traffic_light[NO_OF_ROAD] = {RED_DURATION, GREEN_DURATION};
enum State_Traffic_Light state_traffic_light[NO_OF_ROAD] = {RED, GREEN};
static int trafficLightPin[NO_OF_ROAD][3] = {{0x0002, 0x0004, 0x0008},{0x0010, 0x0020, 0x0040}};

//this function will be called every 1 second.
void run_traffic_light() {
	for(int i = 0; i < NO_OF_ROAD; i++) {
		time_traffic_light[i]--;
		if (time_traffic_light[i] < 0) {
			switch(state_traffic_light[i]) {
			case RED:
				state_traffic_light[i] = AMBER;
				time_traffic_light[i] = amber_duration;
				break;
			case AMBER:
				state_traffic_light[i] = GREEN;
				time_traffic_light[i] = green_duration;
				break;
			case GREEN:
				state_traffic_light[i] = RED;
				time_traffic_light[i] = red_duration;
				break;
			}
		}
	}
}

void display_traffic_light() {
	for(int i = 0; i < NO_OF_ROAD; i++) {
		//tai sao ta khong tat het (dung vong for) roi bat lai?
		//khi dung vong for tat het, proteus xu ly khong noi. co le vong for xu ly viec tat het
		//da khien code nang hon.
		//sau do bat den len theo trang thai:
		switch(state_traffic_light[i]) {
		case RED:
			HAL_GPIO_WritePin(PORT_TRAFFIC_LIGHT, trafficLightPin[i][0], TRAFFIC_LIGHT_ENABLE);
			HAL_GPIO_WritePin(PORT_TRAFFIC_LIGHT, trafficLightPin[i][1] | trafficLightPin[i][2]
																		, TRAFFIC_LIGHT_DISABLE);
			break;
		case AMBER:
			HAL_GPIO_WritePin(PORT_TRAFFIC_LIGHT, trafficLightPin[i][1], TRAFFIC_LIGHT_ENABLE);
			HAL_GPIO_WritePin(PORT_TRAFFIC_LIGHT, trafficLightPin[i][0] | trafficLightPin[i][2]
																		, TRAFFIC_LIGHT_DISABLE);
			break;
		case GREEN:
			HAL_GPIO_WritePin(PORT_TRAFFIC_LIGHT, trafficLightPin[i][0] | trafficLightPin[i][1]
																		, TRAFFIC_LIGHT_DISABLE);
			HAL_GPIO_WritePin(PORT_TRAFFIC_LIGHT, trafficLightPin[i][2], TRAFFIC_LIGHT_ENABLE);
			break;
		}
	}
}

void update_time_traffic_light() {
	updateBuffer(time_traffic_light[0], time_traffic_light[1]);
}
