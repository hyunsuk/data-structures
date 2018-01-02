#include "heap.h"

void HeapInit(Heap *ph, PriorityCompare compare) {
    ph->num_of_data = 0;
    ph->compare = compare;
}

int HeapIsEmpty(Heap *ph) {
    if(ph->num_of_data == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

int GetParentIndex(int index) {
    return index / 2;
}

int GetLeftChildIndex(int index) {
    return index * 2;
}

int GetRightChildIndex(int index) {
    return GetLeftChildIndex(index) + 1;
}

int GetLowestPriorityChildIndex(Heap *ph, int index) {
    if(GetLeftChildIndex(index) > ph->num_of_data) {
        return 0;  // NOTE(hs.lee): Not has children

    } else if(GetLeftChildIndex(index) == ph->num_of_data) {
        return GetLeftChildIndex(index);

    } else {
        if(ph->compare(ph->heap_array[GetLeftChildIndex(index)],
                       ph->heap_array[GetRightChildIndex(index)]) < 0) {
            return GetRightChildIndex(index);

        } else {
            return GetLeftChildIndex(index);

        }
    }
}

void HeapInsert(Heap *ph, HeapData new_data) {
    int new_data_idx = ph->num_of_data + 1;

    while(new_data_idx != 1) {
        if(ph->compare(new_data,
                       ph->heap_array[GetParentIndex(new_data_idx)]) > 0) {
            ph->heap_array[new_data_idx] = \
                ph->heap_array[GetParentIndex(new_data_idx)];
            new_data_idx = GetParentIndex(new_data_idx);

        } else {
            break;

        }
    }

    ph->heap_array[new_data_idx] = new_data;
    ph->num_of_data += 1;
}

HeapData HeapDelete(Heap *ph) {
    HeapData ret_data = ph->heap_array[1];
    HeapData last_element = ph->heap_array[ph->num_of_data];

    int last_element_idx = 1;
    int child_idx;

    while(child_idx = GetLowestPriorityChildIndex(ph, last_element_idx)) {
        if(ph->compare(last_element, ph->heap_array[child_idx]) >= 0) {
            break;
        }

        ph->heap_array[last_element_idx] = ph->heap_array[child_idx];
        last_element_idx = child_idx;
    }
    ph->heap_array[last_element_idx] = last_element;
    ph->num_of_data -= 1;
    return ret_data;
}
