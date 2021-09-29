/*
 * fsm_traffic_light.c
 *
 *  Created on: Sep 29, 2021
 *      Author: ngocc
 */


#include "fsm_traffic_light.h"

enum Mode{NORMAL, CHANGE_RED, CHANGE_AMBER, CHANGE_GREEN};
enum IncreaseMode{IDLE, INCREASE, INCREASE_FAST};


enum Mode mode = NORMAL;
enum IncreaseMode increaseMode = IDLE;
static int blinkingCounter = 25;
static int incCounter = 20;
static int tempDuration = 0;

void fsm_increase_mode(int *duration) {
	switch(increaseMode) {
	case IDLE:
		if (getButtonValue(1) == PRESS) {
			increaseMode = INCREASE;
			*duration = (*duration + 1) % 100;
		}
		break;
	case INCREASE:
		if (getButtonValue(1) == RELEASE) {
			increaseMode = IDLE;
		} else if (getFlagButtonPress1s(1) == 1) {
			increaseMode = INCREASE_FAST;
			incCounter = 20;
		}
		break;
	case INCREASE_FAST:
		if (getButtonValue(1) == RELEASE) {
			increaseMode = IDLE;
		}
		if (incCounter == 20) {
			*duration = (*duration + 1) % 100;
		}
		incCounter--;
		if (incCounter <= 0) incCounter = 20;
		break;
	}
}

void fsm_traffic_light() {
	switch(mode) {
	case NORMAL:
		if (getButtonValue(0) == PRESS && getFlagButtonDelay(0) == 0) {
			mode = CHANGE_RED;
			increaseMode = IDLE;
			tempDuration = red_duration;
			setFlagButtonDelay(0);
			blinkingCounter = 25;
		}
		run_traffic_light();
		update_time_traffic_light();
		display_traffic_light();
		break;
	case CHANGE_RED:
		if (getButtonValue(0) == PRESS && getFlagButtonDelay(0) == 0) {
			mode = CHANGE_AMBER;
			increaseMode = IDLE;
			tempDuration = amber_duration;
			setFlagButtonDelay(0);
			blinkingCounter = 25;
		}
		fsm_increase_mode(&tempDuration);
		updateBuffer(tempDuration, 02);
		if (getButtonValue(1) == RELEASE && getButtonValue(2) == PRESS) {
			red_duration = tempDuration;
			updateBuffer(tempDuration, 88);
		}
		//these are used to blink the led
		if (blinkingCounter == 25) {
			toggleRedLight();
		}
		blinkingCounter--;
		if (blinkingCounter <= 0) {
			blinkingCounter = 25;
		}
		break;
	case CHANGE_AMBER:
		if (getButtonValue(0) == PRESS && getFlagButtonDelay(0) == 0) {
			mode = CHANGE_GREEN;
			increaseMode = IDLE;
			setFlagButtonDelay(0);
			tempDuration = green_duration;
			blinkingCounter = 25;
		}
		fsm_increase_mode(&tempDuration);
		updateBuffer(tempDuration, 03);
		if (getButtonValue(1) == RELEASE && getButtonValue(2) == PRESS) {
			amber_duration = tempDuration;
			updateBuffer(tempDuration, 88);
		}
		//these are used to blink the led
		if (blinkingCounter == 25) {
			toggleAmberLight();
		}
		blinkingCounter--;
		if (blinkingCounter <= 0) {
			blinkingCounter = 25;
		}
		break;
	case CHANGE_GREEN:
		if (getButtonValue(0) == PRESS && getFlagButtonDelay(0) == 0) {
			mode = NORMAL;
			setFlagButtonDelay(0);
			init_traffic_light();
		}
		fsm_increase_mode(&tempDuration);
		updateBuffer(tempDuration, 04);
		//these are used to blink the led
		if (blinkingCounter == 25) {
			toggleGreenLight();
		}
		blinkingCounter--;
		if (blinkingCounter <= 0) {
			blinkingCounter = 25;
		}
		break;
	}
}
