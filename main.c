#include <msp430.h>

/*
 * main.c
 */
#include <msp430.h>
#include "robot.h"

int main(void)
{
    WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer

    initiateRobot();

    while(1){
    moveForward();
    _delay_cycles(1000000);
    stop();
    _delay_cycles(1000000);
    moveBack();
    _delay_cycles(1000000);
    stop();
    _delay_cycles(1000000);
    turnLeft();
    _delay_cycles(300000);
    stop();
    _delay_cycles(1000000);
    turnRight();
    _delay_cycles(300000);
    stop();
    _delay_cycles(1000000);
    turnLeft();
    _delay_cycles(800000);
    stop();
    _delay_cycles(1000000);
    turnRight();
    _delay_cycles(800000);
    stop();
    _delay_cycles(1000000);
    }

    return 0;
}
