#include <stdio.h>

unsigned int a = 5;

int main() {
    printf("%u\n", *&a);
    *&a;
    return 0;
}
