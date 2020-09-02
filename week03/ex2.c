#include <stdio.h>
#define swap(a,b) {int t = *a; *a = *b; *b = t;}

int BubbleSort(int a[], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (a[j] > a[j+1]) swap(&a[j], &a[j+1]);
        }
    }
}

int main()
{
    int arr[] = {9,7,6,4,3,2,1,-1,0, 10};
    int n = sizeof(arr) / sizeof(int) - 1;
    BubbleSort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%i ", arr[i]);

    return 0;
}
