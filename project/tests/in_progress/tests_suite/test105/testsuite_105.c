#include <stdio.h>

int test()
{
   int a = 24680;
   int b = 01234567;
   int c = 0x2468ac;
   int d = 0x2468AC;

   printf("%d\n", a);
   printf("%d\n", b);
   printf("%d\n", c);
   printf("%d\n", d);

   return 0;
}

// vim: set expandtab ts=4 sw=3 sts=3 tw=80 :
int main () {
  int x;
  x = test();
  printf("%d\n", x);
  return 0;
}