/*
 * fsm_traffic_light.c
 *
 *  Created on: Sep 29, 2021
 *      Author: ngocc
 */


#include "fsm_traffic_light.h"

enum Mode{NORMAL, CHANGE_RED, CHANGE_AMBER, CHANGE_GREEN};

enum Mode mode = NORMAL;
static int blinkingCounter = 25;

void fsm_traffic_light() {
	switch(mode) {
	case NORMAL:
		if (getButtonValue(0) == PRESS && getFlagButtonDelay(0) == 0) {
			mode = CHANGE_RED;
			setFlagButtonDelay(0);
		}
		run_traffic_light();
		update_time_traffic_light();
		display_traffic_light();
		break;
	case CHANGE_RED:
		if (getButtonValue(0) == PRESS && getFlagButtonDelay(0) == 0) {
			mode = CHANGE_AMBER;
			setFlagButtonDelay(0);
			blinkingCounter = 25;
		}
		updateBuffer(red_duration, 02);
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
			setFlagButtonDelay(0);
			blinkingCounter = 25;
		}
		updateBuffer(amber_duration, 03);
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
		updateBuffer(green_duration, 04);
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
