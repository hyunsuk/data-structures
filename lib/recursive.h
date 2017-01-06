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
