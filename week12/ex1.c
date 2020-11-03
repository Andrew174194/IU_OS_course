#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
    int rand = open("/dev/random", O_RDWR);
    char *line = malloc(sizeof(char)*20);
    read(rand, line, 20);
    printf("%20s\n", line);
    close(rand);
    free(line);
    return 0;

}