/*
 * 7_seg_display.h
 *
 *  Created on: Sep 22, 2021
 *      Author: ngocc
 */

#ifndef INC_7_SEG_DISPLAY_H_
#define INC_7_SEG_DISPLAY_H_

#define NO_OF_LED7 			4
#define PORT_USED_DISPLAY	GPIOB
#define PORT_ENABLE			GPIOB
#define TURN_ON_SEGMENT		GPIO_PIN_RESET
#define TURN_OFF_SEGMENT	GPIO_PIN_SET
#define ENABLE_LED			GPIO_PIN_RESET
#define DISABLE_LED			GPIO_PIN_SET
//vi minh thuong noi cac pin cua led 7 doan chung voi nhau
//nen minh chi ro gia tri pin bat dau la bao nhieu, roi
//dung vong for shift qua gan gia tri cho nhanh
#define START_PIN			0x0001
//chan enable nhieu led minh cung thuong gan chung voi nhau, nen
//tuong tu, co start_enable_pin
#define START_ENABLE_PIN	0x0080

void display7SEG(int value);
//call this function to switch to the next LED and it's value
void scanLED();
//call this function to update buffer
void updateBuffer(int value1, int value2);

#endif /* INC_7_SEG_DISPLAY_H_ */
