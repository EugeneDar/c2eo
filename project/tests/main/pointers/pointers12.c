//clang -Xclang -ast-dump -fsyntax-only main.c
//#include <stdio.h>

// Проверка инициализации указателей
long long c = 255;
long long d = 10;
long long *pc; // = &c;
// long long *pd; // = &d;
// long long **ppc; // = &c;

int main() {
  pc = &c;
  d = *pc;
  //pd = pc;
//  printf("%lld\n", c);
//  c;
//   printf("%lld\n", d);
//   d;
//  ppc = &pc;
//  d = **ppc;
 printf("%lld\n", d);

  return 0;
}
