#include <ProTrinketKeyboard.h>

#define spacebarPin 5 //labeled RX on Trinket
#define upArrowPin 6 //labeled TX on Trinket
#define downArrowPin 8
#define rightArrowPin 3
#define leftArrowPin 4
#define wPin 1

long nextPress;

void setup() {
  pinMode(spacebarPin, INPUT_PULLUP);
  pinMode(upArrowPin, INPUT_PULLUP);
  pinMode(downArrowPin, INPUT_PULLUP);
  pinMode(rightArrowPin, INPUT_PULLUP);
  pinMode(leftArrowPin, INPUT_PULLUP);
  pinMode(wPin, INPUT_PULLUP);                 

  nextPress = millis();

  TrinketKeyboard.begin();
}

void loop() {
  TrinketKeyboard.poll();

  if (digitalRead(spacebarPin) == LOW) {

    TrinketKeyboard.pressKey(0, KEYCODE_SPACE);
    TrinketKeyboard.pressKey(0, 0);
  }
  if (digitalRead(upArrowPin) == LOW) {

    TrinketKeyboard.pressKey(0, KEYCODE_ARROW_UP);
    TrinketKeyboard.pressKey(0, 0);
  }
  if (digitalRead(downArrowPin) == LOW) {

    TrinketKeyboard.pressKey(0, KEYCODE_ARROW_DOWN);
    TrinketKeyboard.pressKey(0, 0);
  }
  //  if (millis() > nextPress) {
  if (digitalRead(rightArrowPin) == LOW) {

    TrinketKeyboard.pressKey(0, KEYCODE_ARROW_RIGHT);
    TrinketKeyboard.pressKey(0, 0);
  }
  //    nextPress = millis() + 13;
  //  }
  if (digitalRead(leftArrowPin) == LOW) {

    TrinketKeyboard.pressKey(0, KEYCODE_ARROW_LEFT);
    TrinketKeyboard.pressKey(0, 0);
  }
  if (digitalRead(wPin) == LOW) {

    TrinketKeyboard.pressKey(0, KEYCODE_W);
    TrinketKeyboard.pressKey(0, 0);
  }

}
