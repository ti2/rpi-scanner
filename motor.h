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

#ifndef MOTOR_H
#define MOTOR_H

#include <stdint.h>

#define A0_PIN 7	// BCM 4
#define A1_PIN 0	// BCM 17
#define B0_PIN 4	// BCM 23
#define B1_PIN 5	// BCM 24

#define ROTATE_CW	0x00
#define ROTATE_CCW	0x01
#define STEP_NORMAL	0x00
#define STEP_WAVE	0x02
#define STEP_HALF	0x04

void rotate(unsigned int steps, unsigned int speed, uint8_t flags);

#endif // MOTOR_H
