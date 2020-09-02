//Andrey Khoroshavin BS19_02 01/09/20

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
    int n;
    printf("Enter number of elements - ");
    scanf("%d", &n);
    printf("Enter elements - ");
    int arr[n]; 
    for (int i = 0; i < n; i++){
        scanf("%i", &arr[i]);
    }
    BubbleSort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%i ", arr[i]);

    return 0;
}
