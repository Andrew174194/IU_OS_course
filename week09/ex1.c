//Andrey Khoroshavin BS19_02

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define PERIOD 5
#define COUNTER_SIZE 16 //power of 2 (in bits)

//update age status for buffered pages
void ageing(int N, int *b, int *R){
    for(int i = 0; i < N; i++){
        b[i] = b[i] >> 1;					//shift every bit to right
        if (R[i] == 1) b[i] |= (1 << 15);	//add 1 to the left if R-bit = 1
    }
}

//reload the oldest page with new one
void page_load(int N, int* s, int* b, int page){
    int MIN = INT_MAX;
    int MIN_pos = -1;

    for(int i = 0; i < N; i++){
        if (s[i] < MIN){
            MIN_pos = i;
        }
    }

    b[MIN_pos] = page;
    s[MIN_pos] = 0 | ((unsigned long) 1 << (COUNTER_SIZE - 1)); //1 at first pos, 0 - otherwise
}


int main(){
    int size;       //size of mem buffer in page frames
    printf("Enter number of page frames - ");
    scanf("%d", &size);

    FILE *file;
    file = fopen("Lab_input.txt", "r");

    int HIT = 0;
    int MISS = 0;
    int *r_bit = malloc(size * sizeof(int));	//R-bits for buffered pages
    int *buff = malloc(size * sizeof(int));		//numbers of buffered pages
    int *state = malloc(size * (COUNTER_SIZE/8));	//age-state of buffered pages
    for(int i = 0; i < size; i++){
        buff[i] = -1;
    }
    int page, page_fault, step = 0;

//do until end of file will be found
    while(fscanf(file, "%d", &page) != EOF){
        step++;
        page_fault = 1;
        for(int i = 0; i < size; i++){
            if (buff[i] == -1){
                buff[i] = page;
                MISS++;
                HIT--; //it will be negated in next if block
            }
            if (buff[i] == page){
                page_fault = 0;
                HIT++;
                r_bit[i] = 1;
            break;
           }
        }
		
		//current page is not in buffer - page fault occur
        if (page_fault){
            MISS++;
            ageing(size, state, r_bit);
            page_load(size, state, buff, page);
            step = 0;
        }

		//check if time period was passed
        if (step == PERIOD){
            ageing(size, state, r_bit);
            for(int i = 0; i < size; i++){
                r_bit[i] = 0;
            }
            step = 0;
        }
    }

    printf("Total HIT/MISS ratio is %d/%d", HIT, MISS);
    //fclose(file);
    return 0;
}