//Andrey Khoroshavin BS19_02

#include <stdio.h>

int main(int argc, char *argv[])
{
    int arg;
    sscanf(argv[1], "%i", &arg);
    for (int i = 1; i <= arg; i++){
        for (int j = 0; j < arg - i; j++){
            printf(" ");
        }
        for (int j = 0; j < i*2 - 1; j++){
            printf("*");
        }
        for (int j = 0; j < arg - i; j++){
            printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
