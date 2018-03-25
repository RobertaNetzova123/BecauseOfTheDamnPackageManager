#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>

int main (int argc, char **argv) {

	int times = atoi(argv[1]);
	char *pathway = argv[2];
	char error[50] = "./multifork: \0";

	for(int i = 1; i <= times; i++) {
		
		pid_t pid = fork();
		if(pid < 0) {
			
			perror("error with fork");
		}
		else if (pid == 0) { 
			
			if(execl(pathway, pathway, argv[3], 0) == -1) {
				strcat(error, argv[2]);
				perror(error);
				kill(pid, SIGKILL);
			}
		}
		else {
			waitpid(pid, 0, 0);
		}

	}	

}
