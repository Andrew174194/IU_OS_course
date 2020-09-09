//Andrey Khoroshavin BS19_02

#include <stdio.h>
#include <unistd.h>

int main()
{
    int n = 17;
    int parent_pid = (int)getpid();
    fork();
    if ((int)getpid() == parent_pid) printf("Hi from parent");
    else printf("Hi from child");
    printf("[%d - %d]\n", (int)getpid(), n);
    return 0;
}
