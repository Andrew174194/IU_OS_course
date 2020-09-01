//Andrey Khoroshavin BS19_02

#include <stdio.h>
#include <string.h>

int main()
{
    printf("Please write a string to reverse - ");
    char str[256];
    gets(str);
    printf("\nReversed string - ");
    for (int i = strlen(str); i >= 0; i--){
        printf("%c", str[i]);
    }

    return 0;
}
