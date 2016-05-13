// GNU GPL v3
// Yuri Socher Bichibichi, 2016

#include <heap.h>

static Type _index_parent(int index);
static Type _index_child_left(int index);
static Type _index_child_right(int index);
static void _swap(Type *arr, int first, int second);

/*\
|*| Min Heap
\*/

void heap_min_heapfy(Type *arr, int length, int index) {
  Type ileft = _index_child_left(index);
  Type iright = _index_child_right(index);
  Type imin;

  if (ileft < length) {
    if (arr[ileft] < arr[index]) {
      imin = ileft;
    } else {
      imin = index;
    }

    if (iright < length && arr[iright] < arr[imin]) {
      imin = iright;
    }

    if (imin != index) {
      _swap(arr, imin, index);
      heap_min_heapfy(arr, length, imin);
    }
  }
}

void heap_build_min_heap(Type *arr, int length) {
  int i;
  for (i = length / 2 - 1; i >= 0; i--) {
    heap_min_heapfy(arr, length, i);
  }
}

Type heap_minimun(Type *arr) {
  return arr[0];
}

Type heap_extract_min(Type *arr, int length) {
  if (length > 1) {
    Type min = heap_minimun(arr);
    length--;
    arr[0] = arr[length];
    heap_min_heapfy(arr, length, 0);
    return min;
  }
  return OTHERWISE;
}

void heap_min_insert(Type *arr, int length, Type value) {
  arr[length] = INF_POSITIVE;
  heap_min_decrease_key(arr, length, value);
  length++;
}

void heap_min_decrease_key(Type *arr, int index, Type newValue) {
  if (arr[index] > newValue) {
    arr[index] = newValue;
    while (index > 0 && arr[_index_parent(index)] > arr[index]) {
      _swap(arr, index, _index_parent(index));
      index = _index_parent(index);
    }
  }
}

/*\
|*| Max Heap
\*/

Type heap_maximum(Type *arr) {
  return arr[0];
}

Type heap_extract_max(Type *arr, int length) {
  if (length > 1) {
    Type max = heap_maximum(arr);
    length--;
    arr[0] = arr[length];
    heap_max_heapfy(arr, length, 0);
    return max;
  }
  return OTHERWISE;
}

void heap_increase_key(Type *arr, int index, Type newValue) {
  if (arr[index] < newValue) {
    arr[index] = newValue;
    while (index > 0 && arr[_index_parent(index)] < arr[index]) {
      _swap(arr, index, _index_parent(index));
      index = _index_parent(index);
    }
  }
}

void heap_decrease_key(Type *arr, int length, int index, Type newValue) {
  if (arr[index] > newValue) {
    arr[index] = newValue;
    heap_max_heapfy(arr, length, index);
  }
}

void heap_insert(Type *arr, int length, Type value) {
  arr[length] = INF_NEGATIVE;
  heap_increase_key(arr, length, value);
  length++;
}

void heap_max_heapfy(Type *arr, int length, int index) {
  int ileft = _index_child_left(index);
  int iright = _index_child_right(index);
  int imax;

  if (ileft < length) {
    if (arr[ileft] > arr[index]) {
      imax = ileft;
    } else {
      imax = index;
    }
    if (iright < length && arr[iright] > arr[imax]) {
      imax = iright;
    }
    if (imax != index) {
      _swap(arr, imax, index);
      heap_max_heapfy(arr, length, imax);
    }
  }
}

void heap_build_max_heap(Type *arr, int length) {
  int i;
  for (i = length / 2 - 1; i >= 0; i--) {
    heap_max_heapfy(arr, length, i);
  }
}

void heap_sort(Type *arr, int length) {
  int i;
  heap_build_max_heap(arr, length);
  for (i = length - 1; i >= 1; i--) {
    _swap(arr, 0, i);
    length--;
    heap_max_heapfy(arr, length, 0);
  }
}

/*\
|*| Util
\*/

void heap_print_tree(Type *arr, int length) {
  int i, j, power2 = 1, exp = (int) log2((double)length);
  for (i = 0; i < length; i++) {
    printf("%2d ", arr[i]);
    for (j = 0; j < exp; j++) {
      printf("    ");
    }
    if (i + 1 >= power2) {
      printf("\n");
      power2 <<= 1;
      power2 |= 1;
      exp -= 1;
    }
  }
  printf("\n");
}

void heap_print_arr(Type *arr, int length) {
  int i;
  printf("< ");
  for (i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }
  printf(">\n");
}

static Type _index_parent(int index) {
  return (index - 1) / 2;
}

static Type _index_child_left(int index) {
  return index * 2 + 1;
}

static Type _index_child_right(int index) {
  return index * 2 + 2;
}

static void _swap(Type *arr, int first, int second) {
  Type tmp = arr[first];
  arr[first] = arr[second];
  arr[second] = tmp;
}
