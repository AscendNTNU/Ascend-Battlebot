BOARD_TAG=leonardo
BOARD_SUB=atmega32u4
MONITOR_PORT=/dev/ttyACM0
ARDMK_DIR=/usr/share/arduino
ARDUINO_DIR=/arduino-1.8.7
AVR_TOOLS_DIR=/usr
AVRDUDE=/usr/bin/avrdude
CXXFLAGS_STD += -std=gnu++14 -fno-threadsafe-statics
CXXFLAGS += -Ivendor

include $(ARDMK_DIR)/Arduino.mk

