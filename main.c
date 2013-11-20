#include <msp430.h>
#include "robot.h"



int main(void)
{
	initiateRobot();
	while(1){
//		moveRobot(RIGHT);
//		__delay_cycles(1000000);
//		moveRobot(LEFT);
//		__delay_cycles(1000000);
//		moveRobot(BACK);
		moveRobot(FORWARD);
		__delay_cycles(1000000);
		//moveRobot(BACK);
		//moveRobot(FORWARD);
		//__delay_cycles(1000000);
		moveRobot(SMALLLEFT);
		//moveRobot(FORWARD);
		__delay_cycles(1000000);
		moveRobot(SMALLRIGHT);
		//moveRobot(FORWARD);
		__delay_cycles(1000000);
		moveRobot(LARGELEFT);
		//moveRobot(FORWARD);
		__delay_cycles(1000000);
		moveRobot(LARGERIGHT);
		__delay_cycles(1000000);


	}
}

