/*
 * ATtiny104 Interrupt.cpp
 *
 * Created: 10/15/2021 1:44:36 PM
 * Author : zombi
 */ 

#include <avr/io.h>
//#include <util/delay.h>
#include <avr/interrupt.h>

#define LED_ON PORTB |= (1<<PORTB5)
#define LED_OFF PORTB &= ~(1<<PORTB5)
#define LED_TOGGLE PINB |= (1<<PINB5)


int main(void) {

	/* enable the pull-up function */
	PUEB |= 1<<PORTB1;

	/* enable pull-up for button */
	PORTB |= 1<<PORTB1;

	/* configure LED pin as output */
	DDRA |= 1<<DDRA5;

	while(1) {
		/* check the button status (press - 0 , release - 1 ) */
		if(!(PINB & (1<<PINB1))) {
			/*switch on the LED until button is pressed */
			PORTA &= ~(1<<PORTA5);
		}
		else {
			/* switch off the LED if button is released*/
			PORTA |= 1<<PORTA5;
		}
	}
	
		/*DDRB |= (1 << DDRA5);
    while(1) {
		// Set port B5
		PORTB |= (1 << PORTA5);
	}*/

}
