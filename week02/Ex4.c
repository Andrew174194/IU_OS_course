//Andrey Khoroshavin BS19_02

#include <stdio.h>

int main(int arg)
{
    printf("Please enter 2 numbers - ");
    int first;
    int second;
    scanf("%i%i", &first, &second);
    swap(&first, &second);
    printf("\nSwaped numbers - %i %i", first, second);
    return 0;
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}