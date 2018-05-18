#include <stdio.h>
/* Author: Sean O'Donnell */
int main()
{
  unsigned int i;
  unsigned long j;
  unsigned long acc = 0;
  int scan1 = 0;
  int scan2 = 0;
  do {
    printf("Enter A: ");
    scan1 = scanf("%u", &i);
  } while (scan1 != 1);
  do {
    printf("Enter B: ");
    scan2 = scanf("%lu", &j);
  } while (scan2 != 1);
  printf("%u * %lu = ", i, j);
  while (i > 0) {
    if ((i & 1) != 0) {
      acc += j;
    }
    i = i >> 1;
    j = j << 1;
  };
  printf("%lu\n", acc);

  return (0);

}
