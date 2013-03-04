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

#ifndef LASER_H
#define LASER_H

#include <stdint.h>

#define LASER_OFF 0
#define LASER_ON 1

#define LASER_PIN 3		// BCM 22

void setLaser(uint8_t state);

#endif // LASER_H

