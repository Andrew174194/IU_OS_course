#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>


struct f{
    int i_node;
    char names[15][255];
    int count; 
} typedef node;

int main(){

    node nodes[255];

    char path[255] = "/home/andrew/Documents/week10/tmp";
    int index = 0;

    struct dirent *dp;
    DIR *dir = opendir(path);

    while ((dp = readdir(dir)) != NULL)
    {
        int found = 0;
        for (int i = 0; i < index; i++){
            if (nodes[i].i_node == dp->d_ino){
                strcpy(nodes[i].names[nodes[i].count],dp->d_name);
                nodes[i].count++;
                found = 1;
                break;
            }
        }
        if (!found){
            node n;
            n.i_node = dp->d_ino;
            strcpy(n.names[n.count],dp->d_name);
            n.count = 1;
            nodes[index] = n;
            index++;
        }
        found = 0;
        
        //printf("%s %i\n", dp->d_name, dp->d_ino); 
    }
    closedir(dir);

    for (int i = 0; i < index; i++){
        if (nodes[i].count > 1){
            printf("All files and links with i-node %i:\n", nodes[i].i_node);
            for (int j = 0; j < nodes[i].count; j++){
                printf("%s\n", nodes[i].names[j]);
            }
            printf("\n");
        }
    }
    return 0;
} 
