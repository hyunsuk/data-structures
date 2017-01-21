#ifndef LIB_ARRAY_H_
#define LIB_ARRAY_H_

void PrintArray(int *array, int start_idx, int end_idx);

void PrintValue(int *array, int index);
int BsearchArray(int *sorted_list, int list_length, int target);

void Init(ArrayList *list);
void Append(ArrayList *list, ListData data);
int Len(ArrayList *list);

int First(ArrayList *list, ListData *data);
int Next(ArrayList *list, ListData *data);

ListData Remove(ArrayList *list);

void StackInit(ArrayStack *stack);
int IsEmpty(ArrayStack *stack);

void Push(ArrayStack *stack, StackData data);
StackData Pop(ArrayStack *stack);
StackData Peek(ArrayStack *stack);

#endif
