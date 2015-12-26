# camdisplay
Raspberry PiCam display C-Berry TFT

Based on RaspiCam C++ API by the AVA group of UCO.es [http://www.uco.es/investiga/grupos/ava/node/40]
AVA code is partialy bundled (included) because i did not manage to use raspi_still with cmake properly.

## Prerequisites 
* Raspberry Pi
* Admatec C-Berry TFT Display (bcm2835 driver installed)
* Raspberry PiCam 

## Usage

* git clone ...
* cd camdisplay
* mkdir build
* cd build
* cmake ..
* ./camdisplay

It will create one picture and print it out on the TFT screen
