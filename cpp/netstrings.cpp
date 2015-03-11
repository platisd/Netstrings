/*
*	Netstrings.cpp - A simple library for encoding and decoding Netstrings.
*	More on Netstrings: http://cr.yp.to/proto/netstrings.txt
*	Author: Dimitris Platis
*/

#include "netstrings.hpp"

using namespace std;

string encodedNetstring(string plainInput){
	//if the input string is empty, return "error"
	if (plainInput.empty()) throw "String Empty";

	//return a Netstring in the form of [len]":"[string]","
	return  to_string(plainInput.length()) + ":" + plainInput + ",";
}

string decodedNetstring(string netstring){

	//if the Netstring is less than 3 characters, it's either an invalid one or contains an empty string
	if (netstring.length() < 3) throw "Nestring cant be shorter than 3 charachters";
	int semicolonIndex = netstring.find(':');

	// if there's no semicolon, then it's an invalid Netstring
	if (semicolonIndex < 0) throw "Netstring contained no semicolon";

	//parse until the semicolon. Those should be the control digits
	string parsedDigits = netstring.substr(0, semicolonIndex);
	int controlDigits = std::stoi(parsedDigits);

	//if the control digit is smaller than 1, then it's either not a digit or the Netstring is invalid
	if (controlDigits < 1) throw "Controldigit is smaller than 1";

	//parse after the semicolon until the end of the string
	string command = netstring.substr(semicolonIndex+1);

	// if it's an empty string, return "error"
	if (command.empty()) throw "Netstring empty";

	//if last character is a comma, remove it
	if (command.substr(command.length() -1) == ",") command.erase(command.length()-1);

	//if string's length isn't equal with the control digits, it's an invalid Netstring
	if (command.length() != controlDigits) throw "String does not correspond to controldigit";

	return command;
}
