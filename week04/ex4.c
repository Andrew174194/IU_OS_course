//Andrey Khoroshavin BS19_02

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ARG_MAX 64

int main(){
	char com[256];
    printf("Enter the command: ");
	scanf("%256s",com);
    int i = 0; 			//number of symbol in command
	int ar = 0;			//number of argument
	char *args[ARG_MAX];
	args[0]==(char*)malloc(256);
	int j = 0; 			//number of symbol in current argument
	while(com[i] != '\0' && com[i] != '\n'){
		if (com[i] == ' '){
			ar++;
			if (ar == 64){
				printf("Argument overflow");
				return;
			} 
			args[ARG_MAX] ==(char*)malloc(256);
			j = 0;
		}
		else{
			args[ar][j] = com[i];
			j++;
		}
		i++;
	}
	if(fork() == 0){
		execve(args[0],args,NULL);
	}
	return 0;
}
