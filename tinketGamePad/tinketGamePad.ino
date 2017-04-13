#include <ProTrinketKeyboard.h>
byte pins[] = {1, 3, 4};
byte keycodes[] = {KEYCODE_ARROW_LEFT, KEYCODE_ARROW_UP, KEYCODE_ARROW_RIGHT};
bool stateChange;
byte currentStates[] = {HIGH, HIGH, HIGH};
byte prevStates[] = {HIGH, HIGH, HIGH};


void setup() {
  for (byte i = 0; i < sizeof(pins); i++) {
    pinMode(pins[i], INPUT_PULLUP);
  }
  TrinketKeyboard.begin();
}

void loop() {
  TrinketKeyboard.poll();
  stateChange = false;
  for (byte i = 0; i < sizeof(pins); i++) {
    currentStates[i] = digitalRead(pins[i]);
    if (currentStates[i] != prevStates[i]) {
      stateChange = true;
    }
    prevStates[i] = currentStates[i];
  }
  
  if (stateChange){
    TrinketKeyboard.pressKey(0, 0);
    for (byte i = 0; i < sizeof(pins); i++) {
      if (currentStates[i] == LOW) {
        TrinketKeyboard.pressKey(0, keycodes[i]);
      }
    }
 }
}
