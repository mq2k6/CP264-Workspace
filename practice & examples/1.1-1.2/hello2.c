/*
C program structure example
*/
#include<stdio.h>        // preprocessor directive include
int a;                   // global variable declaration
int add(int, int);       // function declaration
int minus(int, int);     // function declaration 
int main()               // main function
{             
  a=1;                   // assign/set value 1 to global variable a
  int b=2;               // declare local variable b and initialize/set it to value 2
  printf("a+b=%d\n", add(a, b));   // function calls
  printf("a-b=%d\n", minus(a, b)); // function calls
  return 0; 
}
// definition/implementation of function add(int, int)
int add(int x, int y)    // function header
{                         
   return x+y;           // function body 
}
// definition/implementation of function minus(int, int)
int minus(int x, int y)  // function header
{
  return x-y;            // function body
}