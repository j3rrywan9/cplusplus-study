#include <iostream>

using namespace std;

void print_array(const int array[], const size_t array_size) {
    for (size_t i {}; i < array_size; i++) {
        cout << array[i] << ' ';
    }
    cout << endl;
}
