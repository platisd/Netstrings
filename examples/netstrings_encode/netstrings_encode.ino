/* Read a string from Serial (remember to send a new line after it) and print out the equivalent it contains
"error" is printed when the string supplied is empty.

Example
Input: test,
Output: 4:test, */


#include <Netstrings.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    Serial.println(encodedNetstring(input));
  }
}
