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

struct Point {
  int x;
  int y;
};

void print_point(struct Point p) { printf("x: %d - y: %d\n", p.x, p.y); }

// NOTE: we cannot just stack allocate a struct here and return it (out of scope
// => cannot be used in python) we need to dynamically allocate it instead
struct Point *get_point() {
  struct Point *p = malloc(sizeof *p);
  p->x = 10;
  p->y = 20;
  return p;
}

struct Student {
  char *name;
};

void print_student_details(struct Student s) { printf("%s\n", s.name); }

struct Student *get_student() {
  struct Student *s = (struct Student *)malloc(sizeof(struct Student));
  s->name = strdup("Test");
  return s;
}

// generic free
void free_ptr(void *ptr) {
  free(ptr);
  ptr = NULL;
  printf("Freed ptr\n");
}
