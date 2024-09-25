#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// gcc -fPIC -shared -o clib.so clib.c

char *display(char *str, int age) {
  printf("My name is %s and my age is %d\n", str, age);
  return "Done";
}

int add(int a, int b) { return a + b; }

char *alloc_mem() {
  char *str = strdup("Hello World");
  printf("alloc_mem() DONE\n");
  return str;
}

void free_mem(char *ptr) {
  printf("free_mem() DONE\n");
  free(ptr);
  ptr = NULL;
}
