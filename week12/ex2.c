#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define BUF_SIZE 16

int main(int argc, char* argv[]){

    int rights = O_CREAT | O_WRONLY;
    int perms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH; 
    int index = 1;
    int n_files = argc - 1;
    if (!strcmp(argv[1], "-a")){
         index = 2;
         n_files = argc - 2;
         rights |= O_APPEND;
    }

    if (n_files == 0){
        printf("Files names arguments requered!");
        exit(1);
    } 

    //open files and create an array of them
    int* file_list = malloc(sizeof(int)*n_files);
    for (int i = 0; i < n_files; i++){
        file_list[i] = open(argv[index+i], rights, perms); 
    }

    //copying
    char buf[BUF_SIZE];
    int subbuf;
    while ((subbuf = read(STDIN_FILENO, &buf, BUF_SIZE)) > 0){
        for (int i = 0; i < n_files; i++){
            write(file_list[i], &buf, subbuf);
        }
    }

    for (int i = 0; i <= n_files; i++){
        close(file_list[index + i]);
    }

    return 0;
}