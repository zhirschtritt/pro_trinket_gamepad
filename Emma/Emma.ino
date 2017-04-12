#include <ProTrinketKeyboard.h>
//
//int pins[] = {0,1,3,4,5,6}; //TX, RX, 3, 4, 5, 6
#define upArrowPin 0 //labeled RX on Trinket
#define downArrowPin 8 //labeled TX on Trinket
#define rightArrowPin 3
#define leftArrowPin 4
#define aPin 5
#define cPin 6

long nextPress;

void setup() {
  pinMode(aPin, INPUT_PULLUP);
  pinMode(upArrowPin, INPUT_PULLUP);
  pinMode(downArrowPin, INPUT_PULLUP);
  pinMode(rightArrowPin, INPUT_PULLUP);
  pinMode(leftArrowPin, INPUT_PULLUP);
  pinMode(cPin, INPUT_PULLUP);                 

  nextPress = millis();

  TrinketKeyboard.begin();
}

void loop() {
  TrinketKeyboard.poll();

  if (digitalRead(aPin) == LOW) {

    TrinketKeyboard.pressKey(0, KEYCODE_A);
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
  if (digitalRead(cPin) == LOW) {

    TrinketKeyboard.pressKey(0, KEYCODE_C);
    TrinketKeyboard.pressKey(0, 0);
  }

}
