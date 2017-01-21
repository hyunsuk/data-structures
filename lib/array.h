#ifndef LIB_ARRAY_H_
#define LIB_ARRAY_H_

#define TRUE 1
#define FALSE 0
#define LIST_LEN 100

#define ARRAY_LENGTH(x)  (sizeof(x) / sizeof(*x))

typedef int ListData;

typedef struct ArrayList {
    ListData arr[LIST_LEN];
    int length;
    int current_position;
} ArrayList;


void PrintArray(int *array, int start_idx, int end_idx);

void PrintValue(int *array, int index);
int BsearchArray(int *sorted_list, int list_length, int target);

void Init(ArrayList *list);
void Append(ArrayList *list, ListData data);
int Len(ArrayList *list);

int First(ArrayList *list, ListData *data);
int Next(ArrayList *list, ListData *data);

ListData Remove(ArrayList *list);

#endif
