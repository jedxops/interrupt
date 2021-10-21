#include<avr/io.h>
#define LED PA5

int
main(void) {

  uint8_t timerOverflowCount=0;
  // Configure PORTA as output
  DDRA = 0xff;
  // Load timer counter with 0
  TCNT0 = 0x00;
  // Set CS00 and CS02 bits in TCCR0B
  TCCR0B = (1 << CS00) | (1 << CS02);
  // TCCR0B = TCCR0B | ((1 << 3) | (1 << 4));

  while (1) {
    // DDRA = 0xff;
    while ((TIFR0 && 0x01) == 0);
    // PORTA ^= (0x01 << LED);
    TCNT0 = 0x00;
    // Clear timer0 overflow flag
    TIFR0 = 0x01;
    timerOverflowCount++;
    if (timerOverflowCount >= 60) {
      PORTA ^= (0x01 << LED);
      timerOverflowCount = 0;
    }
  }
  return 0;
}

/*
#include <avr/io.h>


int
main(void) {
  enable the pull-up function 
  PUEB |= 1<<PORTB1;
  enable pull-up for button 
  PORTB |= 1<<PORTB1;

  configure LED pin as output 
  DDRA |= 1<<DDRA5;
  while(1) {
    check the button status (press - 0 , release - 1 )
    if(!(PINB & (1<<PINB1))) {
      switch on the LED until button is pressed
      PORTA &= ~(1<<PORTA5);
    }
    else {
      switch off the LED if button is released
      PORTA |= 1<<PORTA5;
    }
  }
  return 0;
}*/
