//------------------------------------------------------------------------
// NAME: Mihaela Gadzhalova
// CLASS: XIb
// NUMBER: 18
// PROBLEM: #1
// FILE NAME: tail.c
// FILE PURPOSE:
// Raelisation of the UNIX tail system function


#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int read_stdin();

//**argv - a two-dimensional array from the commadn line
int main(int argc, char **argv) {

	if(argc == 1) {			//check stdin in case without arguments
		return read_stdin();
	}

	int headers = 0; //parameter which count the empty lines;

	for(int i = 1; i < argc; i++) { // i - a counter that shows on which element we are at the moment
		
		char *filename = argv[i]; //arguments for files
		char symbol;
		int lines = 0;
		int max_lines = 10;
		int bytes_count = 0;

		if(argv[i][0] == '-') { 	//check stdin in case of more than one arguments
			if(headers > 0) {
				write(STDOUT_FILENO, "\n", 1);	
			}
			if(argc > 2) {
				write(STDOUT_FILENO,"==> standard input <==\n", 23);
			}
			read_stdin();
			continue;
		}
		
		ssize_t open_file = open(filename,O_RDONLY);
		if(open_file < 0) {		//check if file can be open. If it cannot, print an error message
			char first = strlen("tail: cannot open \'");
      			char second = strlen("\' for reading");
      			char* err = malloc(first + strlen(filename) + second);

      			strcat(err, "tail: cannot open \'");
      			strcat(err, filename);
      			strcat(err, "\' for reading");
      			perror(err);
      			free(err);

      			continue;
		}

		ssize_t read_file = read(open_file, &symbol, 1);
		if(read_file < 0) {		//check if file can be read. If it cannot, print an error message
			char first = strlen("tail: error reading \'");
      			char second = strlen("\'");
      			char* err = malloc(first + strlen(filename) + second);

      			strcat(err, "tail: error reading \'");
      			strcat(err, filename);
      			strcat(err, "\'");
      			perror(err);
      			free(err);
      
			continue;
		}

		if(argc > 2) {
			if(headers > 0) write(STDOUT_FILENO, "\n", 1);
      			write(1, "==> ", 4);
      			write(1, argv[i], strlen(argv[i]));
      			write(1, " <==\n", 5);
      			headers++;
		}
	
		off_t size = lseek(open_file,0,SEEK_END); 	//the size of the file
		
		while(lines < max_lines) {
      			if(bytes_count == size){	
         			lseek(open_file, -size, SEEK_END);
				break;
		// If we reach the end of the file before we could read 10 lines, we return pointer with lseek size before the the end of the file. Then we break so we cannot count lines out of the file.
			}
			lseek(open_file, -2, SEEK_CUR); // we return with 2 positions back form the current state
      			read(open_file, &symbol ,1); // we read a new character from the line
      			bytes_count++;
      			if(symbol == '\n') lines++; //if we reach the end of the line -> lines++
		}

		if(lines < max_lines) {
      			max_lines = lines + 1;
    		}
		lines = 0;
		
		read_file = read(open_file, &symbol, 1);
		while(read_file > 0 && lines < max_lines){

     			if(symbol == '\n') lines++;
			ssize_t wb = write(1 ,&symbol,1);
     			int br_from_write = 0;
     			while(wb != 1){
        			if(wb != 0) {		//if you cant write -> error message
         				char *first = "tail: error writing \'standard output\'";
         				perror(first);
         				br_from_write = 1;
	 				break;
       	 			}
      				wb = write(1 ,&symbol,1);
     			}
     			if(br_from_write == 1)break; //if the parameter was in the cycle, then it should be set on 1. Then we make a check to see if it actually was in the cycle -> if it was then we break the cycle

     			read_file = read(open_file, &symbol, 1);
  		}

		int close_file = close(open_file);
  		if(close_file < 0) {		//check if file is closed. If it cannot, print an error message
    			char first = strlen("tail: error reading \'");
    			char second = strlen("\'");
    			char* err = malloc(first + strlen(filename) + second);
    
    			strcat(err, "tail: error reading \'");
    			strcat(err, filename);
    			strcat(err, "\'");
    			perror(err);
    			free(err);
  		}
	}
	return 0;

}

//------------------------------------------------------------------------
// FUNCTION: read_stdin
// The function read lines from the standard input anr print on the standard output
// the last 10 read
// PARAMETERS: none
//------------------------------------------------------------------------

int read_stdin() {
	
    	int size = 100;
	char symbol[1];
	char *words = malloc(size * sizeof(char));
	int i = 0;
	int lines = 0;
	int normal_state = 0;
	int checking;
	int n = 0;
	int max_lines = 10;

	for(; read(STDIN_FILENO, symbol, 1) != 0; i++) {
		if(i == size) { 	//change the size of the memory if we cant fit in the first we save at first
			size = size * 2;
			words = realloc(words, size * sizeof(char));
		}
		if(symbol[0] == '\n') { 	//if we reach the end of the line -> lines++
			lines++;
		}
		words[i] = symbol[0]; 	
	}

	//check if the file has lines less or even to 10
	//if it hasnt, then we printf all the lines, because they are less than 10
	if(lines < 11) {
		for(int mini = 0; mini <= i; mini++) {
			symbol[0] = words[mini];
			checking = write(STDOUT_FILENO, symbol, 1);
			if(checking < 0) {
				perror("tail: error writing 'standart output'");
                		return 1;
			}
		}
		return 0;
	//or if file has more than 10 lines, we printf only the last 10
	} else {
		normal_state = lines - max_lines;
		int m = 0;
		for(; n != normal_state; m++) {
			if(words[m] == '\n') {
				n++;
			}
		}
	
		for(; m < i; m++) {
			symbol[0] = words[m];
			checking = write(STDOUT_FILENO, symbol, 1);
			if(checking < 0) {
				perror("tail: error writing 'standart output'");
                		return 1;
			}
		}
 	}

	
	return 0;
}

