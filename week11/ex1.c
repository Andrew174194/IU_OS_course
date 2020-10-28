#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(){
    int file = open("ex1.txt", O_RDWR);

    char* mes = "This is a nice day\0";

    ftruncate(file, strlen(mes));
    char *f = mmap(NULL, strlen(mes), PROT_WRITE, MAP_SHARED, file, 0);
    strcpy(f, mes);
    munmap(f, strlen(mes));

    close(file);
    return 0;
}
