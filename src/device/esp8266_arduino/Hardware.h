#ifndef ARDUINO_HARDWARE_H
#define ARDUINO_HARDWARE_H

#include <Arduino.h>

void HWInit();
void HWRestart();
void HWGetUniqeId(char *uid);
void HWLoop();

#endif /* ARDUINO_HARDWARE_H */
