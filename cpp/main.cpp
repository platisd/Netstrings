#include <iostream>

using namespace std;

#include "netstrings.hpp"

int main() {
    cout << decodedNetstring(encodedNetstring("Hello World!")) << endl;
    return 0;
}