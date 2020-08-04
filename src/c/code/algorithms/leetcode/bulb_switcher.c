#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

// LC 319
int bulb_switch(int n) {
    return (int) sqrt(n);
}

int main(void) {
    printf("%d\n", bulb_switch(3));

    return EXIT_SUCCESS;
}
