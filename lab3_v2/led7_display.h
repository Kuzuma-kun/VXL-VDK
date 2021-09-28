/*
 * led7_display.h
 *
 *  Created on: Sep 28, 2021
 *      Author: ngocc
 */

#ifndef INC_LED7_DISPLAY_H_
#define INC_LED7_DISPLAY_H_

#define NO_OF_7SEG		4
#define TURN_ON_SEGMENT	GPIO_PIN_RESET
#define TURN_ON_7SEG	GPIO_PIN_RESET

#define START_SEGMENT_PIN	0x0001
#define START_ENABLE_PIN	0x0080

#define PORT_FOR_SEGMENT	GPIOB
#define PORT_FOR_ENALBE		GPIOB

void display7SEG(int value);

void updateBuffer(int value1, int value2, int value3, int value4);

void scanLED();

#endif /* INC_LED7_DISPLAY_H_ */
