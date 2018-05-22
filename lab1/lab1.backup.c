#include <stdio.h>
/* Author: Sean O'Donnell */
int main()
{
  int a;
  int b;
  unsigned char shiftChar;
  unsigned short shiftShort;
  unsigned short accumulator = 0;
  printf("Enter 2 integers separated by a space: ");
  if (scanf("%i %i", &a, &b) != 2) {
    printf("Error: unable to scan 2 integers separated by a space. Try again.\n");
    printf("Example:\n");
    printf("Enter 2 integers separated by a space: 5 4\n");
  } else if (a < 0 || b < 0) {
    printf("Error: Both integers must be greater than or equal to zero.");
  } else if (a > 255 || b > 255) {
    printf("Error: Both integers must be less than 256.");
  } else {
    shiftChar = (unsigned char)a;
    shiftShort = (unsigned short)b;
    printf("%u * %d = ", shiftChar, shiftShort);
    while (shiftChar > 0) {
      if ((shiftChar & 1) != 0) {
        accumulator += shiftShort;
      }
      shiftChar = shiftChar >> 1;
      shiftShort = shiftShort << 1;
    }
    printf("%d\n", accumulator);
  }
  return (0);
}
