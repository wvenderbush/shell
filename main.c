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
  printf("-------------------\n\n");
  int i = run();
  while (i){
    i = run();
  }
  return 0;
	
}
