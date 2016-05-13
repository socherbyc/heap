// GNU GPL v3
// Yuri Socher Bichibichi, 2016

#include <stdio.h>
#include <stdlib.h>
#include <heap.h>

// main.c

// "aula" 1
void test1(void) {
  int length = 10;
  Type *arr = (Type*) malloc(sizeof(Type) * length);
  arr[0] = 4;
  arr[1] = 1;
  arr[2] = 3;
  arr[3] = 2;
  arr[4] = 16;
  arr[5] = 9;
  arr[6] = 10;
  arr[7] = 14;
  arr[8] = 8;
  arr[9] = 7;

  heap_sort(arr, length);

  printf("-----tree:\n");
  heap_print_tree(arr, length);
  printf("-----arr:\n");
  heap_print_arr(arr, length);
  printf("-----\n");

  free(arr);
}

// "aula" 2
void test2(void) {
  int length = 10;
  Type *arr = (Type*) malloc(sizeof(Type) * length);
  arr[0] = 4;
  arr[1] = 1;
  arr[2] = 3;
  arr[3] = 2;
  arr[4] = 16;
  arr[5] = 9;
  arr[6] = 10;
  arr[7] = 14;
  arr[8] = 8;
  arr[9] = 7;

  heap_build_max_heap(arr, length);

  /*
  heap_extract_max(arr, length);
  length--;
  heap_insert(arr, length, 123); //*/

  /*
  heap_increase_key(arr, 1, 100);
  heap_decrease_key(arr, length, 0, 50); //*/

  printf("-----tree:\n");
  heap_print_tree(arr, length);
  printf("-----arr:\n");
  heap_print_arr(arr, length);
  printf("-----\n");

  free(arr);
}

// operations over min heap
void test3(void) {
  int length = 10;
  Type *arr = (Type*) malloc(sizeof(Type) * length);
  arr[0] = 4;
  arr[1] = 1;
  arr[2] = 3;
  arr[3] = 2;
  arr[4] = 16;
  arr[5] = 9;
  arr[6] = 10;
  arr[7] = 14;
  arr[8] = 8;
  arr[9] = 7;

  heap_build_min_heap(arr, length);

  /*
  printf("minimum: %d\n", heap_extract_min(arr, length));
  heap_min_insert(arr, length - 1, -100); //*/

  printf("-----tree:\n");
  heap_print_tree(arr, length);
  printf("-----arr:\n");
  heap_print_arr(arr, length);
  printf("-----\n");

  free(arr);
}

int main(void) {

  printf("\n\ntest 1:\n");
  test1();
  printf("\n\ntest 2:\n");
  test2();
  printf("\n\ntest 3:\n");
  test3();

  printf(";)\n");

  return 0;
}
