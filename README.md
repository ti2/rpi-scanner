# RPi Scanner

### 1. Overview

This is a project to build a 3D scanner using the Raspberry Pi.

### 2. Requirements

#### 2.1 Hardware

This section contains a list of hardware components used in the creation of the RPi Scanner. Most of the components are generic and can be exchanged for alternatives without many tweaks to the software.

The following components were purchased online:

* [Raspberry Pi Model B, Revision 1](http://www.raspberrypi.org/)
* [Line Laser Diode - 5mW 650nm Red](https://w: ww.adafruit.com/products/1057)
* [Fixed Laser Mounting Stand](https://www.adafruit.com/products/1094)
* [L293D Dual H-Bridge Motor Driver](https://www.adafruit.com/products/807)
* [ST-PM35 Small Stepper Motor](https://www.sparkfun.com/products/10551)

The following components were extracted from a UMAX Astra 1220U paper scanner:

* ULN2003AN Stepper Motor Driver
* M35SP-7 Stepper Motor
* Metal Rod - Diameter: 10mm; Width 425.45mm
* Timing Belt - Width: 3.175mm; Teeth: 380; Pitch: 2.032mm (MXL)

#### 2.2 Software

RPi Scanner depends on the following libraries:

* [WiringPi](https://projects.drogon.net/raspberry-pi/wiringpi/)

### 3. License

The source code for RPi Scanner is licensed under the GNU General Public License, version 3. See [COPYING](COPYING) for details.
