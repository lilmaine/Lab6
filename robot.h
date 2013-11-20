/*
 * robot.h
 *
 *  Created on: Nov 17, 2013
 *      Author: C15Tramaine.Barnett
 */

#ifndef ROBOT_H_
#define ROBOT_H_

#define FORWARD 1
#define BACK 2
#define SMALLLEFT 3
#define LARGELEFT 4
#define SMALLRIGHT 5
#define LARGERIGHT 6

void initiateRobot();
void moveRobot(unsigned char direction);

#endif /* ROBOT_H_ */
