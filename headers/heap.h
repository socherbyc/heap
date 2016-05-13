// GNU GPL v3
// Yuri Socher Bichibichi, 2016

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

typedef int Type;
#define OTHERWISE 0
#define INF_NEGATIVE INT_MIN
#define INF_POSITIVE INT_MAX

// min heap
void heap_min_heapfy(Type *arr, int length, int index);
void heap_build_min_heap(Type *arr, int length);
Type heap_minimun(Type *arr);
Type heap_extract_min(Type *arr, int length);
void heap_min_insert(Type *arr, int length, Type value);
void heap_min_decrease_key(Type *arr, int index, Type newValue);

// max heap
Type heap_maximum(Type *arr);
Type heap_extract_max(Type *arr, int length);
void heap_increase_key(Type *arr, int index, Type newValue);
void heap_decrease_key(Type *arr, int length, int index, Type newValue);
void heap_insert(Type *arr, int length, Type value);
void heap_max_heapfy(Type *arr, int length, int index);
void heap_build_max_heap(Type *arr, int length);
void heap_sort(Type *arr, int length);

// util
void heap_print_tree(Type *arr, int length);
void heap_print_arr(Type *arr, int length);

