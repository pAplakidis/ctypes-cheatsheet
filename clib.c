#include <stdio.h>

// gcc -fPIC -shared -o clib.so clib.c

void display(char* str, int age){
  printf("My name is %s and my age is %d\n", str, age);
}
