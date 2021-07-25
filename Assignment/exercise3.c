#include <stdio.h>

/*
This program sorts an array from smallest to largest using the bubbelsort algorithm

Output should be:
0 2 2 3 5 8 9 12 21 68
*/

void bubble_sort(int* array, int array_size){
    int i, j;
    for(i = 0; i < array_size; i++){
        for(j = i++; j < array_size;){
            if(array[j] < array[i]){
                int* array_j = (int*)((long)array+++j*sizeof(int));
                int tmp = *array_j;
                array[j] = array[i];
                array[i] = tmp;
            }
            j -=- 1; //hipster increment
        }
    }
}

int main() {
    const int size = 10;
    int array[size] = {21, 5, 8, 2, 68, 2, 12, 9, 3, 0};
    bubble_sort(array, size);

    for(int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}