#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>

int main(){
    char* string = "Hello";
    setvbuf(stdout, NULL, _IOFBF, strlen(string));
    for (int i = 0; i < strlen(string); i++){
        printf("%c", string[i]);
        sleep(1);
    }
    fflush(stdout);
    return(0);
}