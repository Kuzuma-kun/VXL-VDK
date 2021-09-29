/*
 * 7_seg_display.c
 *
 *  Created on: Sep 22, 2021
 *      Author: ngocc
 */
#include "main.h"
#include "7_seg_display.h"



static int Led7Buffer[NO_OF_LED7] = {0,0,0,0};
static int currentLED = 0;
static uint8_t displayData[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D
								,0x7D, 0X07, 0X7F, 0X6F};

//this function display value on a 7-seg LED
void display7SEG(int value) {
	uint8_t temp = displayData[value];
	int turnOnGroup = 0, turnOffGroup = 0;
	for(int i = 0; i < 7; i++) {
		if (temp % 2 == 1) {
			turnOnGroup = turnOnGroup | START_PIN << i;
		} else {
			turnOffGroup = turnOffGroup | START_PIN << i;
		}
		temp = temp >> 1;
	}
	HAL_GPIO_WritePin(PORT_USED_DISPLAY, turnOnGroup, TURN_ON_SEGMENT);
	HAL_GPIO_WritePin(PORT_USED_DISPLAY, turnOffGroup, TURN_OFF_SEGMENT);
}

//this function choose a 7-seg LED among multiple LED to turn on.
void scanLED() {
	//turn off all LED
	int group = START_ENABLE_PIN;
	for(int i = 0; i < NO_OF_LED7; i++) {
		group = group | (START_ENABLE_PIN << i);
	}
	HAL_GPIO_WritePin(PORT_ENABLE, group, DISABLE_LED);
	//update LED value
	display7SEG(Led7Buffer[currentLED]);
	//turn that LED on
	HAL_GPIO_WritePin(PORT_ENABLE, START_ENABLE_PIN << currentLED, ENABLE_LED);

	currentLED = (currentLED + 1) % NO_OF_LED7;
}

//this function update Buffer. this buffer will be showed on all LEDs
void updateBuffer(int value1, int value2) {
	Led7Buffer[0] = value1/10;
	Led7Buffer[1] = value1%10;
	Led7Buffer[2] = value2/10;
	Led7Buffer[3] = value2%10;

}
