//Andrey Khoroshavin BS9_02

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

size_t getsize(void * p) {
    size_t * in = p;
    if (in) { --in; return *in; }
    return -1;
}

void* my_realloc(void* ptr, size_t size){
    void* new;

    if (ptr == NULL){
        //no pointer got -> create new 
        new = malloc(size);
    }
    else {
        //we have a pointer
        if (sizeof(ptr) > size) {
            //existing size is bigger than new size -> allocate new mem size and free old one
            new = malloc(size);

            //copy memory
            memcpy(new, ptr, sizeof(ptr));

            //deallocate old pointer    
            //free(ptr);
        }

        else {
            // if new allocates more mem than old -> assign same place but with smaller allocated size
            new = ptr;
        }
    }

    return new;    
}

int main() {
    int a = 10;
    int* p = malloc(sizeof(int));
    p = &a;
    printf("Valiable a has value %d in memory address %i with size %i\n", *p, p, sizeof(*p));
    int* p1 = my_realloc(p, 2);
    printf("Now Valiable a has value %d in memory address %i with size %i\n", *p1, p1, sizeof(p1));
    return 0;
}