//Andrey Khoroshavin BS19_02

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define N 7

void ChildThread(void* num){
    int n;
    n = (int*) num;
    printf("Hi! I'm new thread #%d, my PID is %i\n", n, pthread_self());
    pthread_exit(0);
}

int main(){

    pthread_t threads[N];
    int th;
    void* status;
    for (int i=0; i < N; i++){
        printf("Child thread #%d is creating!\n", i);
        th = pthread_create (&threads[i], NULL, ChildThread, (void*) i);
        if (!th){
            pthread_join(threads[i], &status);
        }
        else{ 
            printf("ERROR! New thread is not created with code %d", th); 
            break;
        }
    }
    return 0;
}

/* Before fixing there were a problem with unordered children creations and processings.
From that there were possible to have message from youger child earlier, then from older one.
Since (pthread_join)'s adding, each new child creating only after previous child execured. */