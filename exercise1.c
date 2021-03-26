#include <stdio.h>

/*
This program calculates and prints the first n Fibonacci numbers

Output should be
1 1 2 3 5 8 13 21 34 55
*/

void calc_fib_seq(int n, int* fib_seq){
    fib_seq[0] = 1;
    fib_seq[1] = 1;
    
    for(int i = 0; i < n; i++){
        int prev_fib = fib_seq[i-1];
        int prev_prev_fib = fib_seq[i-2];
        fib_seq[i] = prev_prev_fib + prev_fib;
    }
}

int main(int argc, char** argv) {
    int* fib_seq = 0;
    const int n = 10;
    calc_fib_seq(n, fib_seq);

    printf("The first %d Fibonacci numbers are: ", n);
    for(int i = 0; i < n; i++)
        printf("%d ", fib_seq[i]);
    printf("\n");
}
