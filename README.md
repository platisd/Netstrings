# Netstrings
A simple Arduino library to decode and encode Netstrings by Dimitris Platis.
C++ version included in /cpp by David Jensen.

## Introduction
This library allows easy decoding and encoding of Netstrings. For more information on Netstrings refer to http://cr.yp.to/proto/netstrings.txt

## API
### String encodedNetstring(String plainInput)
Provide an input in plain text to this function and it will return a Netstring. The string "error" will be returned, if an empty string is supplied.
* **Example**

    
```arduino
String netstring = encodedNetstring("send this as a netstring");
//nestring == 24:send this as a netstring,
```

### String decodedNetstring(String netstring)
Provide an input encoded as a Netstring and if the Netstring is valid, this function will return the string that was used to generate the Netstring. If the supplied Netstring is not valid, then an "error" string is returned.

* **Example**

```arduino
String plainInput = decodedNetstring("11:*@*#(SADASD,")
// plainInput == "*@*#(SADASD"
```