/**
 * addsub_main.c
 * test driver program containing the main function 
 */
#include <stdio.h>
#include "addsub.h"
int a;
int main()
{             
  a=1; 
  int b=2;
  printf("a+b=%d\n", add(a, b)); 
  printf("a-b=%d\n", minus(a, b));
  return 0; 
}