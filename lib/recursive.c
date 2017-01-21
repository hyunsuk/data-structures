#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "array.h"
#include "recursive.h"

long Factorial(int n) {
    if (n <= 0) { // termination
        return 1;
    } else {
        return n * Factorial(n - 1);
    }
}

int Fibonacchi(int n) {
    if (n == 1) { // termination
        return 0;
    } else if (n == 2) { // termination
        return 1;
    } else {
        return Fibonacchi(n - 1) + Fibonacchi(n - 2);
    }
}

int RecursiveBsearch(int *sorted_list,
                     int start_idx, int end_idx, int target) {
    if (start_idx > end_idx) {
        return -1; // termination - not found
    }

    PrintArray(sorted_list, start_idx, end_idx);

    int seek = (start_idx + end_idx) / 2;

    if (target == sorted_list[seek]) {
        return seek; // termination - found
    } else if (target < sorted_list[seek]) {
        return RecursiveBsearch(sorted_list, start_idx, seek -1, target);
    } else {
        return RecursiveBsearch(sorted_list, seek + 1, end_idx, target);
    }
}

void HanoiTowerMove(int disc_number, char from, char by, char to) {
    if (disc_number == 1) {
        printf("disc 1 move: %c -> %c \n", from, to);
    } else {
        HanoiTowerMove(disc_number - 1, from , to, by);
        printf("disc %d move: %c -> %c \n", disc_number, from, to);
        HanoiTowerMove(disc_number - 1, by, from, to);
    }
}
