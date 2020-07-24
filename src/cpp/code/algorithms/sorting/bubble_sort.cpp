#include <array>
#include <iostream>

#include "array_utils.h"

using namespace std;

void bubble_sort(int *array, const size_t array_size) {
    for (size_t i {}; i < array_size; i++) {
        bool swapped {false};

        for (size_t j {}; j < array_size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
                swapped = true;
            }
        }

        if (!swapped) return;
    }
}

int main() {
    int array[] {64, 34, 25, 12, 22, 11, 90, 42};
    const size_t n = sizeof(array) / sizeof(array[0]);

    cout << "Original array: ";
    print_array(array, n);
    bubble_sort(array, n);
    cout << "Sorted array: ";
    print_array(array, n);

    return EXIT_SUCCESS;
}
