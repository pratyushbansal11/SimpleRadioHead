#ifndef SIMPLE_RADIOHEAD_H
#define SIMPLE_RADIOHEAD_H

#include <Arduino.h>

class SimpleRadioHead {
  public:
    SimpleRadioHead(int txPin, int rxPin);
    void begin();
    void sendMessage(const char* message);
    bool receiveMessage(char* buffer, int bufferSize);

  private:
    int _txPin;
    int _rxPin;
};
#endif