#include <stdio.h>

long long a = 6;
long long b = 8;

void fun(long long x) {
  a = b * x;
  printf("%d\n", a);
  printf("%d\n", b);
}

int main(){
  fun(5);
  fun(b);
}

