BOARD_TAG=leonardo
BOARD_SUB=atmega32u4
MONITOR_PORT = /dev/ttyACM0
ARDUINO_DIR=$(HOME)/software/arduino-1.8.7
AVR_TOOLS_DIR=/usr
AVRDUDE=/usr/bin/avrdude
CXXFLAGS_STD += -std=gnu++14 -fno-threadsafe-statics
CXXFLAGS += -I$(HOME)/Arduino/libraries

include /usr/share/arduino/Arduino.mk

