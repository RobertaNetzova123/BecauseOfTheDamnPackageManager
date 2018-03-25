//------------------------------------------------------------------------
// NAME: Mihaela Gadzhalova
// CLASS: XIb
// NUMBER: 18
// PROBLEM: #1
// FILE NAME: bytes.c
// FILE PURPOSE:
// Open the file as the first argument & miss N bytes (as the second argument) & print the characters to the end of the file

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv) {
	
	const char *file_name = argv[1];
	int skip_bytes = atoi(argv[2]);
	int printed_bytes = atoi(argv[3]);

	int open_file = open(file_name, 0, O_RDONLY);

	if(open_file < 0) {
		perror("cannot open the file");
		return 2;
	}

	off_t peace = lseek(open_file, skip_bytes, SEEK_SET);
	
	for(int i = 0; i < printed_bytes; i++) {
		char symbol;
		int read_file = read(open_file, &symbol, 1);
		if(read_file == 0) break;
		write(1, &symbol, 1);
	}

	close(open_file);

	return 0;

}
