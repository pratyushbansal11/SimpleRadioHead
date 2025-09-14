#include "SimpleRadioHead.h"

SimpleRadioHead::SimpleRadioHead(int txPin, int rxPin) {
  _txPin = txPin;
  _rxPin = rxPin;
}

void SimpleRadioHead::begin() {
  pinMode(_txPin, OUTPUT);
  pinMode(_rxPin, INPUT);
  Serial.begin(9600);
}

void SimpleRadioHead::sendMessage(const char* message) {
  Serial.print("Sending: ");
  Serial.println(message);
}

bool SimpleRadioHead::receiveMessage(char* buffer, int bufferSize) {
  if (Serial.available()) {
    int len = Serial.readBytesUntil('\n', buffer, bufferSize - 1);
    buffer[len] = '\0';
    return true;
  }
  return false;
}
