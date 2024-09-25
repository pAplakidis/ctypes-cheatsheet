#include <stdio.h>

// gcc -fPIC -shared -o clib.so clib.c

char *display(char *str, int age) {
  printf("My name is %s and my age is %d\n", str, age);
  return "Done";
}

int add(int a, int b) { return a + b; }
