#include <msp430.h>
#include "robot.h"
/*
 * robot.c
 *
 *  Created on: Nov 19, 2013
 *      Author: C15Tramaine.Barnett
 */

void initiateRobot() {
	WDTCTL = WDTPW | WDTHOLD;                 // stop the watchdog timer

	P1DIR |= BIT2;                // TA0CCR1 on P1.2
	P1DIR |= BIT1;                // TA0CCR1 on P1.2
	P2DIR |= BIT1;                // TA0CCR1 on P1.2
	P2DIR |= BIT0;                // TA0CCR1 on P1.2

	P1SEL |= BIT2;                // TA0CCR1 on P1.2
	P1SEL |= BIT1;                // TA0CCR1 on P1.2
	P2SEL |= BIT1;                // TA0CCR1 on P1.2
	P2SEL |= BIT0;                // TA0CCR1 on P1.2

	TA0CTL &= ~MC1 | MC0;            // stop timer A0
	TA1CTL &= ~MC1 | MC0;            // stop timer A0

	TA0CTL |= TACLR;                // clear timer A0
	TA1CTL |= TACLR;                // clear timer A0

	TA0CTL |= TASSEL1;           // configure for SMCLK
	TA1CTL |= TASSEL1;           // configure for SMCLK

	TA0CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)
	TA0CCR1 = 60;                // set duty cycle to 25/100 (25%)

	TA1CCR0 = 100;  // set signal period to 100 clock cycles (~100 microseconds)
	TA1CCR1 = 60;                // set duty cycle to 25/100 (25%)

	TA0CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
	TA0CCTL0 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode

	TA1CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
	TA1CCTL0 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode

	TA0CTL |= MC0;                // count up
	TA1CTL |= MC0;				  //count up

//	while (1) {
//		__delay_cycles(1000000);
//		TACCR1 = 50;            // set duty cycle to 50/100 (50%)
//		__delay_cycles(1000000);
//		TACCR1 = 60;            // set duty cycle to 75/100 (75%)
//		__delay_cycles(1000000);
//		TACCR1 = 25;            // set duty cycle to 25/100 (25%)
//	}

}

void moveRobot(unsigned char direction) {
	switch (direction) {
	//
	// update player position based on direction of movement
	//
	case LARGERIGHT:
		TA0CCR1 = 25;
		__delay_cycles(500000);
		TA0CCR1 = 60;            // set duty cycle to 25/100 (25%)
		break;

	case SMALLRIGHT:
		TA0CCR1 = 25;
		__delay_cycles(200000);
		TA0CCR1 = 60;            // set duty cycle to 25/100 (25%)
		break;

	case LARGELEFT:
		TA1CCR1 = 25;
		__delay_cycles(500000);
		TA1CCR1 = 60;            // set duty cycle to 25/100 (25%)
		break;

	case SMALLLEFT:
		TA1CCR1 = 25;
		__delay_cycles(200000);
		TA1CCR1 = 60;            // set duty cycle to 25/100 (25%)
		break;

	case FORWARD:

		TA0CCR1 = 60;
		TA1CCR1 = 60;
		TA0CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
		TA0CCTL0 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode

		TA1CCTL1 |= OUTMOD_7;        // set TACCTL1 to Reset / Set mode
		TA1CCTL0 |= OUTMOD_5;        // set TACCTL1 to Reset / Set mode
		break;

	case BACK:

		TA0CCR1 = 50;
		TA1CCR1 = 50;

		TA0CCTL1 |= OUTMOD_5;        // set TA0CCTL1 to Reset mode
		TA0CCTL0 |= OUTMOD_7;        // set TA0CCTL1 to Reset / Set mode

		TA1CCTL1 |= OUTMOD_5;        // set TA1CCTL1 to Reset mode
		TA1CCTL0 |= OUTMOD_7;        // set TA1CCTL1 to Reset / Set mode
		break;

	}
}
