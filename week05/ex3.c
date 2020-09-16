#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define B_SIZE 64

int ind = 0;
int buffer[B_SIZE];

int wake_prod = 0, wake_cons = 0;

void producer() {
	while (1) {

        int number = 1000;

		if (ind >= B_SIZE){
			while (!wake_prod){
                sleep(0.1);
            }
            wake_prod = 0;
        }
        else if (ind <= 0){
            wake_cons = 1;
        }
        else {
		buffer[ind] = number++;
		ind++;
        }
		

	}
	pthread_exit(NULL);
}

void consumer() {
	while(1) {

		if (ind >= B_SIZE - 1){
			while (!wake_cons){
                sleep(0.1);
            }
            wake_cons = 0;
        }
        else if (ind <= 0){
            wake_prod = 1;
        }
        else {
            buffer[ind] = NULL;
		    ind--;  
        }
    }
	pthread_exit(NULL);
}

int main(){
    pthread_t cons, prod;

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    while (1){
        fprintf(stderr, "Top element is %d at index %d\n", buffer[ind], ind);
        sleep(10);
    }

    //pthread_join(cons, NULL);
    //pthread_join(prod, NULL);
    return 0;
}