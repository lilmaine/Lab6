#include <msp430.h>
#include "robot.h"



int main(void)
{
	initiateRobot();
	while(1){
		moveRobot(RIGHT);
	}
}

