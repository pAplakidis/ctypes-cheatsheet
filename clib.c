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

int sum(int *arr, int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum;
}

int *inc_array(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    arr[i]++;
  }
  return arr;
}

// NOTE: we dynamically allocate the array so that we can return it without
// scope problems (check WARNING if using stack variable)
int *get_array() {
  int *arr = malloc(10 * sizeof(int));
  for (int i = 0; i < 10; i++) {
    arr[i] = i;
  }
  return arr;
}

void free_array(int *arr) {
  free(arr);
  arr = NULL;
  printf("Array freed\n");
}
