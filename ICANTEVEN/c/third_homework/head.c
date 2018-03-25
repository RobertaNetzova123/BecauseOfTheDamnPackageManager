//------------------------------------------------------------------------
// NAME: Mihaela Gadzhalova
// CLASS: XIb
// NUMBER: 18
// PROBLEM: #1
// FILE NAME: head.c
// FILE PURPOSE:
// Realisation of a program that displays the first 10 lines of the a.txt file
//--

//------------------------------------------------------------------------
// FUNCTION: xxyyzz main
// Open, Read, Print the first 10 lines and close the file
// PARAMETERS:
// char text - place the charachers read into this variable
//--------------------

#include <stdio.h>
#include <fcntl.h> // a library for the functions open(), read(), write(), close()

int main() {

	int open_file = open("a.txt", O_RDONLY);
	if(open_file < 0) {

		perror("Fail to open the file"); //print an error if cannot open the file
		return -1;
	}
	
	char text;
	for(int i = 0; read(open_file, &text, 1) > 0 && i < 10;) 
	{
		write(1, &text, 1); //print on the console
		if(text == '\n') {
			i++;
		}//if the byte you have accepted is a new line, encrease the variable with 1
	}

	close(open_file); //closing the file
	return 0;
}



