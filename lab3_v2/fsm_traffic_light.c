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
		}
		updateBuffer(0, 02);
		break;
	case CHANGE_AMBER:
		if (getButtonValue(0) == PRESS && getFlagButtonDelay(0) == 0) {
			mode = CHANGE_GREEN;
			setFlagButtonDelay(0);
		}
		updateBuffer(0, 03);
		break;
	case CHANGE_GREEN:
		if (getButtonValue(0) == PRESS && getFlagButtonDelay(0) == 0) {
			mode = NORMAL;
			setFlagButtonDelay(0);
			init_traffic_light();
		}
		updateBuffer(0, 04);
		break;
	}

}
