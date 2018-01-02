#ifndef LIB_HEAP_H_
#define LIB_HEAP_H_

#define TRUE 1
#define FALSE 0

#define HEAP_LEN 100

typedef char HeapData;
typedef int PriorityCompare(HeapData d1, HeapData d2);

typedef struct _heap {
    PriorityCompare *compare;
    int num_of_data;
    HeapData heap_array[HEAP_LEN];
} Heap;

void HeapInit(Heap *ph, PriorityCompare compare);
int HeapIsEmpty(Heap *ph);

void HeapInsert(Heap *ph, HeapData data);
HeapData HeapDelete(Heap *ph);

#endif
