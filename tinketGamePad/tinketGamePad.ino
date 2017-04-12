#include <ProTrinketKeyboard.h>
int pins[] = {0, 1, 3, 4, 5, 6};
char prevStates[] = {HIGH, HIGH, HIGH, HIGH , HIGH, HIGH};
int keycodes[] = {KEYCODE_SPACE, KEYCODE_ARROW_UP, KEYCODE_ARROW_DOWN, KEYCODE_ARROW_RIGHT, KEYCODE_ARROW_LEFT};

void setup() {
  for (byte i = 0; i < sizeof(pins); i++) {
    pinMode(i, INPUT_PULLUP);
  }
  TrinketKeyboard.begin();
}

void loop() {
  TrinketKeyboard.poll();
  for (byte i = 0; i < sizeof(pins); i++) {
    if (prevStates[i] != digitalRead(pins[i])) {
      if (digitalRead(pins[i]) == LOW) {
        TrinketKeyboard.pressKey(0, keycodes[i]);
      }
      else {
        TrinketKeyboard.pressKey(0, 0);
      }
    }
  }
}
