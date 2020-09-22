//Andrey Khoroshavin BS19_02 22/09/20
//Shortest job first scheduler algorithm

#include <stdio.h>

//BubbleSort for jobs order with respect of execution time
#define swap(a,b) {int t = *a; *a = *b; *b = t;}
int Exec_Sort(int a[], int exe[], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - 1; j++){
            if (a[j] == -1 || a[j+1] == -1) continue;
            if (exe[a[j]] > exe[a[j+1]]) swap(&a[j], &a[j+1]);
        }
    }
}
//BubbleSort for arrival time
int Time_Sort(int a[], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size - 1; j++){
            if (a[j] > a[j+1]) swap(&a[j], &a[j+1]); 
        }
    }
}

//put new process' number to last position of queue
int queue_add(int q[], int p){
    int i = 0;
    while (q[i] != -1){
        i++;
    }
    q[i] = p;
    return i;       //return putting index (just in case)
}

//take first process' number from queue
int queue_del(int q[]){
    int i = 0;
    int proc = q[0];
    while (q[i+1] != -1){
        q[i] = q[i+1];
        i++;
    }
    q[i] = -1;
    return proc;    //return process' number
}

int main(){
    int n = 0;              //number of processes
    printf("Number of processes - ");
    scanf("%d", &n);
    printf("Write arrival time at first, space and execution time second\n");

    int ex_time[n];         //array of burst times
    int ar_time[n];         //array of arrival times

    for (int i = 0 ; i < n; i++){
        printf("%d process - ", (i + 1));
        scanf("%d%d", &ar_time[i], &ex_time[i]);
    }
    Time_Sort(ar_time, n);       //sort by arrival time
    
    int time = 0;           //number of time slot
    int buzy = 0;           //is CPU buzy now    
    int cur_proc = 0;       //current process 
    int next_proc = 0;      //number of next to wait process
    int remain_time = 0;    //current process remaining time
    int done[n];            //processes execution time
    int wait_time[n];       //processes waiting time
    int queue[n];           //queue for arrived but waiting processes
    for (int i = 0; i < n; i++){
        wait_time[i] = 0;
        done[i] = 0;
        queue[i] = -1; 
    }
    
    while (1){  //every process has ended
        //read for new arrived processes
        while (time == ar_time[next_proc]){
            queue_add(queue, next_proc);
            Exec_Sort(queue, ex_time, n);
            next_proc++;
        }
        //process is executing
        if (buzy){
            remain_time--;
            time++;
            if (remain_time == 0){
                //end of process
                done[cur_proc] = time;
                buzy = 0;
                //check if all tasks were completed
                int all_done = 1;
                for (int i = 0; i < n; i++)
                //done[i] = 0 iff process i did not complete  
                    if (done[i] == 0) all_done = 0; 
                if (all_done == 1) break;
            }
        }
        //CPU is free - start new process
        if (!buzy){
            cur_proc = queue_del(queue);
            remain_time = ex_time[cur_proc];
            wait_time[cur_proc] = time - ar_time[cur_proc];
            buzy = 1;
        }
    }

    //report writing
    int tat = 0;                //total turnaround time
    int twt = 0;                //total waiting time
    for (int i = 0; i < n; i++){
        tat += done[i] - ar_time[i];
        twt += wait_time[i];
    }
    printf("\nTotal completion time - %d\n", time);
    printf("Turnaround time - %d\n", tat);
    printf("Waiting time - %d\n", twt);
    printf("Average Turnaround time - %f\n", ((float)tat / n));
    printf("Average waitiong time - %f\n", ((float)twt/n)); 

    //additional info for each process
    printf("\nProc.\tArr.T\tWait.T\tStart.T\tExec.T\tDone.T\tTAr.T\n");
    for (int i = 0; i < n; i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n", (i+1), ar_time[i], wait_time[i], 
            (ar_time[i] + wait_time[i]), ex_time[i], done[i], (done[i] - ar_time[i]));
    }
}