#!/bin/bash
echo "COMPILING"
./build.sh
echo "COMPILING DONE"

echo "UPLOADING"
arduino-cli upload -b arduino:avr:nano:cpu=atmega328old -p COM4 -i ~/Documents/software/turnTableDriver/build/arduino.avr.nano/turnTableDriver.ino.hex
echo "UPLOADING COMPLETE"
exit

#:cpu=atmega328old
