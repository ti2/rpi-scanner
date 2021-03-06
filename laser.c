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

#include "laser.h"
#include <wiringPi.h>

void setLaser(uint8_t state)
{
	digitalWrite(LASER_PIN, state);
}
