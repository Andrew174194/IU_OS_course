#include <stdio.h>
#include <stdlib.h>

int main(){

    int DEADLOCK = 0;
    struct FILE;
    FILE *file_in = fopen("dl_check.txt", "r");

    int pros, res;
    fscanf(file_in, "%i %i", &pros, &res);

    fscanf(file_in, "\n");

    int *Requist = malloc(sizeof(int)*res*pros);
    int *Current = malloc(sizeof(int)*res*pros);
    int *Available = malloc(sizeof(int)*res);
    int *Existence = malloc(sizeof(int)*res);

    int *Done = malloc(sizeof(int)*pros);
    int G_Done = 0;

    //reading
    for(int i = 0; i < res; i++)
        fscanf(file_in, "%i", &Existence[i]);

    fscanf(file_in, "\n");

    for(int i = 0; i < res; i++)
        fscanf(file_in, "%i", &Available[i]);

    fscanf(file_in, "\n");

    for(int i = 0; i < pros; i++)
        for(int j = 0; j < res; j++)
            fscanf(file_in, "%i", &Current[i*res + j]);

    fscanf(file_in, "\n");

    for(int i = 0; i < pros; i++)
        for(int j = 0; j < res; j++)
            fscanf(file_in, "%i", &Requist[i*res + j]);

    fclose(file_in);

    //processing
    while(!DEADLOCK && !G_Done){
        int jobDone = 0;
        for(int i = 0; i < pros; i++){
            if (Done[i]) continue; //pass already done process
            printf("Check process %i...\n", i);
            //check if porcess i has enough resources
            for(int j = 0; j < res; j++){
                if (Requist[i*res + j] > Available[j] + Current[i*res + j]) break; //no
                else{
                    if (j == res - 1){                          //yes
                        Done[i] = 1;
                        printf("Process %i done!\n", i);
                        jobDone = 1;
                        for(int k = 0; k < res; k++){
                            Available[k] += Current[i*res + k];
                        }
                    }
                }
            }
            if (jobDone) break;
            printf("No process was done... :(\n");
        }
        if (jobDone){
        //check if all processes are done
            for (int j; j < pros; j++){
                G_Done = 1;     //assume they are done
                if (!Done[j]){ //some not done found -> not all done
                    G_Done = 0;
                    break;
                }
            }
            printf("\nNew iteration!\n");
        }
        //all processes were computed and no job done -> deadlock occurs
        else DEADLOCK = 1;
    }

    //output file
    FILE *file_out = fopen("dl_out.txt", "r+");

    if (G_Done) fprintf(file_out, "No deadlock occurs");
    else{
        fprintf(file_out, "Next processes were not done because of deadlock:");
        for (int i = 0; i < pros; i++){
            if (!Done[i]) fprintf(file_out, " %i", i);
        }
    }
    fclose(file_out);

    return 0;
}