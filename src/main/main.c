#include "mcu_support_package/inc/stm32f10x.h"
#define ASSIGNMENT_PART_1_BUTTON_LED    1
#define ASSIGNMENT_PART_2_LED_BLINKING  2
#define ASSIGNMENT_PART_3_THREE_BUTTONS 3

int main (void){
	
		RCC->APB2ENR |= 0x00000444;
		GPIOA->CRL &= 0x00000000;
		GPIOA->CRL |= 0x00000333;
	
		while(1){
		GPIOA->ODR ^=0x0000001;
		for(int i = 0; i<1000000; i++);
		GPIOA->ODR ^=0x0000001;
		GPIOA->ODR ^=0x0000002;
		for(int i = 0; i<1000000; i++);
		GPIOA->ODR ^=0x0000002;
		GPIOA->ODR ^=0x0000004;
		for(int i = 0; i<1000000; i++);
		GPIOA->ODR ^=0x0000004;
		for(int i = 0; i<1000000; i++);
		}
		return 0;
	
}
