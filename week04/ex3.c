//Andrey Khoroshavin BS19_02

#include <stdio.h>
#include <stdlib.h>

int main(){
	char com[256];
    printf("Enter the command: ");
	scanf("%256s",com);
	system(com);	
	return 0;
}
