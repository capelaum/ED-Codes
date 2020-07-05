#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void swap_int(int* ptr, int i, int j){
  // Verify pointer
  if(!ptr){
    // NULL Pointer
    return;
  }else{
    // Valid Pointer
    // Swap values
    int t = ptr[i];
    ptr[i] = ptr[j];
    ptr[j] = t;
    return;
  }
}//end swap_int();

Heap *init_heap(int size) {
  Heap *heap = (Heap *) malloc(sizeof(Heap));
  if(heap == NULL)
    return NULL;

  heap->data = (int *) malloc(size*sizeof(int));
  
  if(heap->data == NULL) {
    free(heap);
    return NULL;
  }

  heap->size = size;
  return heap;
}//end init_heap();

void max_heap_int(Heap *heap, int input[], int size){
  int f; // Aux index variable
  int* array;
  // Verify valid Array
  if(heap == NULL || input == NULL){
    // Invalid Pointer
    return;
  }else{
    array = heap->data;
    // Setting the first element
    array[0] = input[0];
    /*
        By definition, an Heap is a Array/Tree
      where every index i in [0, size-1] of the array v
      is valid the following:

              v[i/2] >= v[i]      if f is odd
              v[i/2 - 1] >= v[i]  if f is even

        To construct a Heap, we must iterate over all index
      i in [1, size-1] and make the definition valid through
      all the array.
    */
    for(int i=1; i<size; ++i){
      // Test if the index is even
      // array[0...i-1] is a Heap
      f = i; 
      array[i] = input[i]; // Putting the element into the Heap
      
      if(i%2 != 0){
        // Odd index
        // Move the elements until the definition is satisfied
        while(array[f/2] < array[f]){
          swap_int(array, f/2, f);
          f/=2;
        }
      }else{
        // Even index
        // Move the elements until the definition is satisfied
        while (f / 2 >= 1 && array[f / 2 - 1] < array[f]) {
          swap_int(array, f, f/2 - 1);
          f/=2;
        }
      }
    }
    //array[0...size-1] is a Heap
  }
}//end max_heap_int();

void print_heap_int(Heap* heap){
  // Test Valid Pointer
  if(heap){
    // Printing
    for(int i=0; i<heap->size; i++){
      printf("%d. %d\n", i, ((int*) heap->data)[i]);
    }
  }
}//end print_heap_int();

void print_heap_float(Heap* heap){
  // Test Valid Pointer
  if(heap){
    // Printing
    for(int i=0; i<heap->size; i++){
      printf("%d. %f\n", i, ((float*) heap->data)[i]);
    }
  }
}//end print_heap_float();

void print_heap_double(Heap* heap){
  // Test Valid Pointer
  if(heap){
    // Printing
    for(int i=0; i<heap->size; i++){
      printf("%d. %f\n", i, ((double*) heap->data)[i]);
    }
  }
}//end print_heap_double();

void sift_down_int(int* ptr, int m){
  // Verify pointer
  if(!ptr){
    // Some NULL Pointer
    return;
  }else{
    // Valids Pointers
    /*
      The Basis for the Sift Down function is, that
      given the root node array[0], we sift down
      through the heap tree until its correct position

      Hyphotesis:
      => array[0] >= array[1] && array[0] >= 2: Do nothing
      => if the previous condition is not satisfied,
      we swap the parent node and continue moving it to your correct position.
    */
    int p=0, f=1, root=ptr[0];
    while(f <= m){
      // The element ptr[f] is going to keep track
      // of the biggest Children
      // Getting the Biggest Children Index
      if(f < m && ptr[f] < ptr[f+1]){
        // Left Children smaller than the
        // Right one. Increment f to the Index of the Biggest.
        ++f;
      }
      // If the root is bigger or equal to the
      // biggest children, we must leave the algorithm
      // Otherwise, we swap the root with the children
      if(root >= ptr[f]) break;
      else
        swap_int(ptr, p, f);
      // Now we update the indexes and keep
      // testing the algorithm
      // Remember: We must check if the f index is even or odd.
      p=f;
      f = 2*f + 1;
    }
    ptr[p] = root;
    // By the end of it, the root node will
    // be positioned in its correct position.
    return;
  }
}//end sift_down_int();

void HeapSort_int(Heap* heap){
  // Verify pointers
  if(!heap || !heap->data){
    // Some NULL Pointer
    return;
  }else{
    // Valid Pointers
    /*
    Being ptr a Heap, we have that in the beginning of each
    interaction the valids properties are valids:

    1º) ptr[0...m] is a Heap.
    2º) ptr[0...m] <= ptr[m+1...size]
    3º) ptr[0...size] is a permutation of the original ptr.
     */
    int step = 0;
    int size = heap->size - 1;
    for(int m = size; m > 0; --m){
      printf("####### STEP %d OF HEAPSORT ######\n", step);
      print_heap_int(heap);
      // 1º We swap the first element with the mth element
      swap_int(heap->data, 0, m);
      printf("####### MIDDLE STEP (SWAPPING) %d of HEAPSORT\n", step);
      print_heap_int(heap);
      // 2º We execute the Sift Down Algorithm on the
      // the same array, but by only in the m-1 elements.
      sift_down_int(heap->data, m-1);
      ++step;
    }
    // By the End, the Array will be in crescent order
    // and we do nothing more
    return;
  }
}//end HeapSort_int();

void free_heap(Heap* heap){
  // Verify valid pointer
  if(heap){
    free(heap->data);
    free(heap);
  }
  return;
}//end free_heap();
