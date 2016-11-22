#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include "proc.h"

int run(){

	//### START COMMAND RUNNER ###

	char *input = malloc(256);
	char line[100];
	char *s;

	printf("--> ");
	fgets(line, sizeof(line), stdin);
	*(strchr(line, '\n')) = NULL;

	input = line;
	char *args[10];

	int i = 0;
	while (input != 0) {
		args[i] = strsep(&input, " ");
		i++;
	}
	args[i] = NULL;

	//### END COMMAND RUNNER ###

	int pid = fork();

	if (pid == -1) {
		char* error = strerror(errno);
		printf("Fork Error: %s\n", error);
		return 1;
	}

	else if (pid == 0) {
		execvp(args[0], args);  

		char* error = strerror(errno);
		printf("Shell Error on %s: %s\n", args[0], error);
		return 0;
	}

	else {
		int cstat;
		waitpid(pid, &cstat, 0);
		return 1;
	}

	return 1;
}