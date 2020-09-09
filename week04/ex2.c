//Andrey Khoroshavin BS19_02

#include <stdio.h>
#include <unistd.h>

#define TIMES 5

int main()
{
    for (int i = 0; i < TIMES; i++){
        fork();
    }
    sleep(5);
    return 0;
}

/*
After 5 forks we have 2^5 = 32 ex2 processes 

bash─┬─ex2─┬─ex2─┬─ex2─┬─ex2─┬─ex2───ex2
     │     │     │     │     └─ex2
     │     │     │     ├─ex2───ex2
     │     │     │     └─ex2
     │     │     ├─ex2─┬─ex2───ex2
     │     │     │     └─ex2
     │     │     ├─ex2───ex2
     │     │     └─ex2
     │     ├─ex2─┬─ex2─┬─ex2───ex2
     │     │     │     └─ex2
     │     │     ├─ex2───ex2
     │     │     └─ex2
     │     ├─ex2─┬─ex2───ex2
     │     │     └─ex2
     │     ├─ex2───ex2
     │     └─ex2
     └─pstree
*/
