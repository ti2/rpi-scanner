/*
 * Copyright (C) 2013  Chris Howard
 *
 * This file is part of rpi-scanner.
 *
 * rpi-scanner is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * rpi-scanner is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with rpi-scanner.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
#include "motor.h"

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

	while (1)
	{
		rotate(10, 8, ROTATE_CCW | STEP_NORMAL);
	}

	return EXIT_SUCCESS;
}
