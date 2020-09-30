//Andrey Khoroshavin BS9_02

#include <stdio.h>
#include <stdlib.h>

int main(){
    int N; //number of elements
    scanf("%d", &N);                        //ask N
    int* array = malloc(N * sizeof(int));   //allocate memory
    for (int i = 0; i < N; i++){
        *(array + sizeof(int) * i) = i;     //assign to 0-(N-1)
    }
    for (int i = 0; i < N; i++){
        printf("%d ", *(array + sizeof(int) * i));  //print array
    }
    free(array);                            //deallocate memory
    return 0;
}