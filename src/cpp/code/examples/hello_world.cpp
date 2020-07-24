#include <iostream>
#include <string>

using namespace std;

string say_hello() {
    return string("Hello, world!");
}

int main() {
    cout << say_hello() << endl;
    return EXIT_SUCCESS;
}
