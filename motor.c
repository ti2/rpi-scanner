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

#include "motor.h"
#include <wiringPi.h>

static const uint8_t fullSequence[4] =
{
	0x0c,	// 1100
	0x06,	// 0110
	0x03,	// 0011
	0x09,	// 1001
};

static const uint8_t waveSequence[4] =
{
	0x08,	// 1000
	0x04,	// 0100
	0x02,	// 0010
	0x01	// 0001
};

static const uint8_t halfSequence[8] =
{
	0x0c,	// 1100
	0x04,	// 0100
	0x06,	// 0110
	0x02,	// 0010
	0x03,	// 0011
	0x01,	// 0001
	0x09,	// 1001
	0x08	// 1000
};

static void step(uint8_t phase);
static void rotateCW(unsigned int steps, unsigned int speed, const uint8_t* sequence, uint8_t length);
static void rotateCCW(unsigned int steps, unsigned int speed, const uint8_t* sequence, uint8_t length);

void rotate(unsigned int steps, unsigned int speed, uint8_t flags)
{
	const uint8_t* sequence;
	uint8_t length = 4;

	if (flags & HALF_STEP)
	{
		sequence = halfSequence;
		length <<= 1;
	}
	else if (flags & WAVE_STEP)
		sequence = waveSequence;
	else
		sequence = fullSequence;
	
	if (flags & ROTATE_CCW)
		rotateCCW(steps, speed, sequence, length);
	else
		rotateCW(steps, speed, sequence, length);
}

void step(uint8_t phase)
{
	digitalWrite(A0_PIN, phase & (1 << 0));
	digitalWrite(A1_PIN, phase & (1 << 1));
	digitalWrite(B0_PIN, phase & (1 << 2));
	digitalWrite(B1_PIN, phase & (1 << 3));
}

void rotateCW(unsigned int steps, unsigned int speed, const uint8_t* sequence, uint8_t length)
{
	int i, j;

	for (i = 0; i < steps; ++i)
	{
		for (j = 0; j < length; ++j)
		{
			step(sequence[j]);
			delay(speed);
		}
	}
}

void rotateCCW(unsigned int steps, unsigned int speed, const uint8_t* sequence, uint8_t length)
{
	int i, j;

	for (i = 0; i < steps; ++i)
	{
		for (j = length - 1; j >= 0; --j)
		{
			step(sequence[j]);
			delay(speed);
		}
	}
}

