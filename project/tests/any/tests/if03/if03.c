#include "stdio.h"
int x = 1;
int y = 2;
int r;
int main() {
    if (x > y)
        r = x;
    else
        r = y;
    printf("%d\n", r);
    r;
    return 0;
}
