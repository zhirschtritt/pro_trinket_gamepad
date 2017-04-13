#include <ProTrinketKeyboard.h>
byte pins[] = {0,1,3,4,5,6};
byte keycodes[] = {KEYCODE_SPACE, KEYCODE_ARROW_UP, KEYCODE_ARROW_DOWN, KEYCODE_ARROW_RIGHT, KEYCODE_ARROW_LEFT, KEYCODE_W};
bool stateChange;   
byte currentStates[sizeof(pins)];
byte prevStates[sizeof(pins)];


void setup() {
  for (byte i = 0; i < sizeof(pins); i++) {
    pinMode(pins[i], INPUT_PULLUP);
    currentStates[i] = HIGH;
    prevStates[i] = HIGH;
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
