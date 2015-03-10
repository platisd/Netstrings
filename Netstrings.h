/*
*	Netstrings.h - A simple library for encoding and decoding Netstrings.
*	More on Netstrings: http://cr.yp.to/proto/netstrings.txt
*	Author: Dimitris Platis
*/
#ifndef Netstrings_h
#define Netstrings_h

#include "Arduino.h"

/* encodedNetstring accepts a String as an argument and returns the equivalent Netstring. If an empty string is used, then the string "error" is returned */
String encodedNetstring(String plainInput);

/* decodedNetstring accepts a Nestring as an argument (WITHOUT the trailing ",") and returns the equivalent string. If an invalid Netstring is used, then the string "error" is returned */
String decodedNetstring(String netstring);

#endif
