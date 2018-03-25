//------------------------------------------------------------------------
// NAME: Mihaela Gadzhalova
// CLASS: XIb
// NUMBER: 18
// PROBLEM: #1
// FILE NAME: tail.c
// FILE PURPOSE:
// Raelisation of the system function tail

#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char **argv)
{
	for(int i=1;i<argc;i++) { 

		int open_file = open(argv[i],0,O_RDONLY);
		char symbol;
		int lines = 0;
		int d;
		off_t size = lseek(open_file,0,SEEK_END); //size of the file
		off_t place;
		ssize_t rb;

		if(argc > 2) {
			write(1,"==> ",4);
			write(1,argv[i],strlen(argv[i]));
			write(1," <==\n",5);
		}
		
		for(int i = -2; lines < 10; i--) {
			place = lseek(open_file,i,SEEK_END);
			ssize_t already_read = read(open_file, &symbol ,1);
			if(symbol == '\n') lines++;
				
		}

		lines--;
		if(lines > 10) { 
			for(d = place; d < size -1; d++) {
			
				ssize_t already_read = read(open_file,&symbol,1);
				ssize_t already_wrote = write(STDOUT_FILENO,&symbol,1);
				d++;
			}
			
		}
		if(lines <= 10) {
			do{
				rb = read(open_file,&symbol,1);
				ssize_t wb = write(STDOUT_FILENO,&symbol,1);
	
			}while(rb > 0);
		} 
		lines = 0;
		close(open_file);
	}
	return 0;
}
