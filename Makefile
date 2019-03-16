BOARD_TAG=leonardo
BOARD_SUB=atmega32u4
MONITOR_PORT = /dev/ttyACM0
AVR_TOOLS_DIR=/usr
#ARDUINO_DIR=/software/arduino-1.8.9
AVRDUDE=/usr/bin/avrdude
CXXFLAGS_STD += -std=gnu++14 -fno-threadsafe-statics
CXXFLAGS += -Ivendor
OBJDIR=bin

include /usr/share/arduino/Arduino.mk

