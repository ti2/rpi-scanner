/*
 * Copyright (C) 2013  Chris Howard
 *
 * This file is part of RPi Scanner.
 *
 * RPi Scanner is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * RPi Scanner is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with RPi Scanner.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
#include "motor.h"
#include "laser.h"

int main(int argc, const char* argv[])
{
	if (wiringPiSetup() != 0)
	{
		fprintf(stderr, "Failed to setup wiringPi.\n");
		return EXIT_FAILURE;
	}

	pinMode(A0_PIN, OUTPUT);
	pinMode(A1_PIN, OUTPUT);
	pinMode(B0_PIN, OUTPUT);
	pinMode(B1_PIN, OUTPUT);
	pinMode(LASER_PIN, OUTPUT);
	
	int length = 1380;
	int step = 0;
	int phase = 0;
	uint8_t stepMode = STEP_NORMAL;
	uint8_t direction = ROTATE_CW;

	setLaser(LASER_ON);

	while (1)
	{
		rotate(1, 8, direction | stepMode);

		if (++step >= length)
		{
			step = 0;
			direction = ROTATE_CCW;

			if (++phase == 2)
			{
				break;
			}
		}
	}

	setLaser(LASER_OFF);

	return EXIT_SUCCESS;
}
