#include <ProTrinketKeyboard.h>
int pins[] = {0, 1, 3, 4, 5, 6};
bool pinStates[] = {false, false, false, false , false, false};
int keycodes[] = {KEYCODE_SPACE, KEYCODE_ARROW_UP, KEYCODE_ARROW_DOWN, KEYCODE_ARROW_RIGHT, KEYCODE_ARROW_LEFT};

long nextPress;

void setup() {
  for (byte i = 0; i < sizeof(pins); i++) {
    pinMode(i, INPUT_PULLUP);
  }
  nextPress = millis();
  TrinketKeyboard.begin();
}

void loop() {
  TrinketKeyboard.poll();
  for (byte i = 0; i < sizeof(pins); i++) {
    if (digitalRead(pins[i]) == LOW) {
      TrinketKeyboard.pressKey(0, keycodes[i]);
      TrinketKeyboard.pressKey(0, 0);
    }
  }
}
