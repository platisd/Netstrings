/*
*	Netstrings.cpp - A simple library for encoding and decoding Netstrings.
*	More on Netstrings: http://cr.yp.to/proto/netstrings.txt
*	Author: Dimitris Platis
*/

#include "Netstrings.h"

String encodedNetstring(String input){
	unsigned int len = input.length();
	if (!len) return "error"; //if the input string is empty, return "error"
	return len + String(":" + input + ","); //return a Netstring in the form of [len]":"[string]","
}

String decodedNetstring(String input){
	if (input.length() < 3) return "error"; //if the Netstring is less than 3 characters, it's either an invalid one or contains an empty string
	int semicolonIndex = input.indexOf(':');
	if (semicolonIndex < 0) return "error"; // if there's no semicolon, then it's an invalid Netstring
	String parsedDigits = input.substring(0, semicolonIndex); //parse until the semicolon. Those should be the control digits
	int controlDigits = parsedDigits.toInt();
	if (controlDigits < 1) return "error"; //if the control digit is smaller than 1, then it's either not a digit or the Netstring is invalid
	String command = input.substring(semicolonIndex+1); //parse after the semicolon until the end of the string
	if (!command.length()) return "error"; // if it's an empty string, return "error"
	if (command.length() != controlDigits) return "error"; //if string's length isn't equal with the control digits, it's an invalid Netstring
	return command;
}
