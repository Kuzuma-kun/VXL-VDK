/*
 * led7_display.c
 *
 *  Created on: Sep 28, 2021
 *      Author: ngocc
 */
#include "main.h"
#include "led7_display.h"

static int LedBuffer[NO_OF_7SEG] = {1,2,3,4};

static int dataDisplay[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66
							,0x6D,0x7D, 0X07, 0X7F, 0X6F};

static int currentLED = 0;
uint8_t shiftAmountForSegment = 0xff;
uint8_t shiftAmountForEnable7seg = 0xff;

//BSRR:
//32bit, 16low bit, with bit 1 decide to set that pin to high.
//16high bit, with bit 1 decide to set that pin to low.
//if bit 0, ignore (don't do anything)
//BRR:
//32bit, 16low bit, with bit 1 decide to set that pin to low.
//16high bit, with bit 1 decide to set that pin to high.
//if bit 0, ignore (don't do anything)
void display7SEG(int value) {
	int temp = dataDisplay[value];
	//if shiftAmountForSegment is not specified, do once, and use forever.
	if (shiftAmountForSegment == 0xff) {
		shiftAmountForSegment = 0;
		int temp_shift = START_SEGMENT_PIN;
		while (temp_shift > 1) {
			temp_shift = temp_shift >> 1;
			shiftAmountForSegment++;
		}
	}
	if (TURN_ON_SEGMENT == GPIO_PIN_RESET) {
		PORT_FOR_SEGMENT->BRR = temp;
		PORT_FOR_SEGMENT->BRR = ~(temp) << 16;
	} else {
		PORT_FOR_SEGMENT->BSRR = temp << shiftAmountForSegment;
	}
}

void updateBuffer(int value1, int value2, int value3, int value4) {
	LedBuffer[0] = value1;
	LedBuffer[1] = value2;
	LedBuffer[2] = value3;
	LedBuffer[3] = value4;
}

void scanLED() {
	if (currentLED >= NO_OF_7SEG) {
		currentLED = 0;
	}
	//if shiftAmountForEnable7seg is not specified, do once, and use forever.
	if (shiftAmountForEnable7seg == 0xff) {
		shiftAmountForEnable7seg = 0;
		int temp_shift = START_ENABLE_PIN;
		while (temp_shift > 1) {
			temp_shift = temp_shift >> 1;
			shiftAmountForEnable7seg++;
		}
	}
	int temp = 0x0001;
	//tao ra 0x000f
	for(int i = 0; i < NO_OF_7SEG - 1; i++) {
		temp = temp | (temp << 1);
	}
	//dung no de tat het cac den:
	if (TURN_ON_7SEG == GPIO_PIN_RESET) {
		//neu de bat den (RESET), tat den thi phai SET (BSRR)
		PORT_FOR_ENALBE->BSRR = temp << shiftAmountForEnable7seg;
	} else {
		PORT_FOR_ENALBE->BRR = temp << shiftAmountForEnable7seg;
	}
	//sau do cap nhat gia tri moi
	display7SEG(LedBuffer[currentLED]);
	//sau do bat den len
	temp = 0x0001;
	if (TURN_ON_7SEG == GPIO_PIN_RESET) {
		PORT_FOR_ENALBE->BRR = temp << currentLED;
	} else {
		PORT_FOR_ENALBE->BSRR = temp << currentLED;
	}
	currentLED++;
}
