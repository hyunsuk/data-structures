#ifndef __LIB_RECURSIVE_H__
#define __LIB_RECURSIVE_H__

long factorial(int n)
{
    if (n <= 0) { // termination
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int fibonacchi(int n)
{
    if (n == 1) { // termination
        return 0;
    } else if (n == 2) { // termination
        return 1;
    } else {
        return fibonacchi(n - 1) + fibonacchi(n - 2);
    }
}

int recursive_binary_search(int *sorted_list,
        int start_idx, int end_idx, int target)
{
    if (start_idx > end_idx) {
        return -1; // termination - not found
    }

    print_array(sorted_list, start_idx, end_idx);

    int seek = (start_idx + end_idx) / 2;

    if (target == sorted_list[seek]) {
        return seek; // termination - found
    } else if (target < sorted_list[seek]) {
        return recursive_binary_search(sorted_list, start_idx, seek -1, target);
    } else {
        return recursive_binary_search(sorted_list, seek + 1, end_idx, target);
    }
}

void hanoi_tower_move(int disc_number, char from, char by, char to)
{
    if (disc_number == 1) {
        printf("disc 1 move: %c -> %c \n", from, to);
    } else {
        hanoi_tower_move(disc_number - 1, from , to, by);
        printf("disc %d move: %c -> %c \n", disc_number, from, to);
        hanoi_tower_move(disc_number - 1, by, from, to);
    }
}
#endif
