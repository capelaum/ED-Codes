#ifndef __HEAP_H__
#define __HEAP_H__

/**
 * @typedef Heap
 * Heap Data Structure.
 */
typedef struct heap{
  void* data;
  int size;
} Heap;

/**
 * Swap the values of ptr[i] and ptr[j].
 * @param ptr    Integers Array.
 * @param i Index i.
 * @param j Index j.
 */
void swap_int(int* ptr, int i, int j);

/**
 * Initialize the Heap structure.
 * @param size Size of the Array.
 * @return     Pointer for the Heap.
 */
Heap *init_heap(int size);

/**
 * Builds a Max-Heap from an Array of Integers.
 * @param  ptr Array of Integers.
 * @param size Size of the Array.
 */
void max_heap_int(Heap *heap, int *ptr, int size);

/**
 * Builds a MIn-Heap from an Array of Integers.
 * @param ptr  Array of Integers.
 * @param size Size of the Array.
 */
void min_heap_int(int* ptr, int size);

/**
 * Buids a Max-Heap from an Array of Floats.
 * @param  ptr  Array of Floats.
 * @param  size Size of the Array.
 */
void max_heap_float(float* ptr, int size);

/**
 * Buids a Min-Heap from an Array of Floats.
 * @param  ptr  Array of Floats.
 * @param  size Size of the Array.
 */
void min_heap_float(float* ptr, int size);

/**
 * Builds a Max-Heap from an Array of Doubles.
 * @param  ptr  Array of Doubles.
 * @param  size Size of the Array.
 */
void max_heap_double(double* ptr, int size);

/**
 * Builds a Min-Heap from an Array of Doubles.
 * @param  ptr  Array of Doubles.
 * @param  size Size of the Array.
 */
void min_heap_double(double* ptr, int size);

/**
 * Prints the Heap of Integers into the console.
 * @param heap Heap Pointer.
 */
void print_heap_int(Heap* heap);

/**
 * Prints the Heap of Floats into the console.
 * @param heap Heap Pointer.
 */
void print_heap_float(Heap* heap);

/**
 * Prints the Heap of Doubles into the console.
 * @param heap Heap Pointer.
 */
void print_heap_double(Heap* heap);

/**
 * Function that takes an Array of Integers and reorganizes it.
 * @param heap Array of Integers.
 * @param m Size of the Array.
 */
void sift_down_int(int* ptr, int m);

/**
 * Executes the HeapSort Algorithm into the Heap.
 * @param heap Heap Pointer.
 */
void HeapSort_int(Heap* heap);

/**
 * Free the memory associated to the Heap.
 * @param heap Heap Pointer.
 */
void free_heap(Heap* heap);
#endif
