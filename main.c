#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "proc.h"
#include "func.h"

int main(){
	//execvp("clear", args);
	printf("\033[2J");
	printf("Welcome to SeaShell\n");


	while (1){
		run();
	}
	return 0;
	
}