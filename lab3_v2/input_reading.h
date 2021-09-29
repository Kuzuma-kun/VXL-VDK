/*
 * input_reading.h
 *
 *  Created on: Sep 28, 2021
 *      Author: ngocc
 */

#ifndef INC_INPUT_READING_H_
#define INC_INPUT_READING_H_

#include "main.h"
//if change NO_OF_BUTTON, go to input_reading and change pinValue + buttonBuffer
#define NO_OF_BUTTON 		3
//wait time until debouncing
#define WAIT_TIME 			2
#define DURATION_1_SECOND 	100

#define BUTTON_PORT		GPIOA
#define PRESS			GPIO_PIN_RESET
#define RELEASE 		GPIO_PIN_SET

void read_button();

int getButtonValue(int num_of_button);

int getFlagButtonPress1s(int num_of_button);

//this flag can only be pull down if button is released.
void setFlagButtonDelay(int num_of_button);

int getFlagButtonDelay(int num_of_button);


#endif /* INC_INPUT_READING_H_ */
