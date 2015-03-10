/* Read a Netstring from Serial (do NOT send a new line after it) and print out the string it contains
"error" is printed when the netstring supplied is empty.

Example
Input: 4:test,
Output: test */


#include <Netstrings.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil(',');
    Serial.println(decodedNetstring(input));
  }
}
