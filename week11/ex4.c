#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


int main(){
    struct stat file;
    int r_file = open("ex1.txt", O_RDWR);
    int w_file = open("ex1.memcpy.txt", O_CREAT | O_RDWR);

    fstat(r_file, &file);
    ftruncate(w_file, file.st_size);
    char *f_read = mmap(NULL, file.st_size, PROT_READ, MAP_SHARED, r_file, 0);
    char *f_write = mmap(NULL, file.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, w_file, 0);
    memcpy(f_write, f_read, file.st_size);

    close(r_file);
    close(w_file);
    return 0;
}