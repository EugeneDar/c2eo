#include <stdio.h>
int
test()
{
	unsigned long long x;
	
	x = 0;
	x = x + 1;
	if (x != 1)
		return 1;
	return 0;
}
int main () {
  int x;
  x = test();
  printf("%d\n", x);
  return 0;
}