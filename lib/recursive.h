#ifndef LIB_RECURSIVE_H_
#define LIB_RECURSIVE_H_

long Factorial(int n);
int Fibonacchi(int n);
int RecursiveBsearch(int *sorted_list,
        int start_idx, int end_idx, int target);

void HanoiTowerMove(int disc_number, char from, char by, char to);

#endif
