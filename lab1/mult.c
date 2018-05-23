#include <stdio.h>
#define DEBUG 0
/* Author: Sean O'Donnell */

unsigned short shiftProduct(int a, int b)
{
  unsigned short product = 0; /* accumulate product of a and b */
  unsigned char shiftR = (unsigned char)a; /* cast a to char for right-shift */
  unsigned short shiftL = (unsigned short)b;  /* cast b to short for left-shift */
  /* stop when char is 0 */
  while (shiftR > 0) {
    if (DEBUG) printf("have a %u, ", shiftR);
    /* bitwise-and char with 1 */
    if ((shiftR & 1) != 0) {
      product += shiftL; /* add current short value to accumulator */
      if (DEBUG) printf("adding %d yields %d.\n", shiftR, product);
    } else if (DEBUG) {
      printf("not adding %d, still at %d.\n", shiftL, product);
    }
    /* shift char to right by 1 (padded with zeros) */
    shiftR = shiftR >> 1;
    /* shift short to left by 1 */
    shiftL = shiftL << 1;
  }
  return (product);
}

int main()
{
  int a, b; /* user input */
  unsigned short product;
  printf("enter 2 integers separated by a space: ");
  /* scan 2 integer input and check for errors */
  if (scanf("%i %i", &a, &b) != 2) {
    printf("error: unable to scan 2 integers separated by a space. Try again.\nExample:\n");
    printf("enter 2 integers separated by a space: 5 4\n");
  } else if (a < 0 || b < 0) {
    printf("error: both integers must be greater than or equal to zero.\n");
  } else if (a > 255 || b > 255) {
    printf("error: both integers must be less than 256.\n");
  } else {
    /* calculate the product */
    product = shiftProduct(a, b);
    /* print the decimal and hex values */
    printf("%i * %i = ", a, b);
    printf("%d (decimal) = 0x%04x (hex).\n", product, product);
  }
  return (0);
}
