//------------------------------------------------------------------------
// NAME: Peter Milev
// CLASS: XIb
// NUMBER: 20
// PROBLEM: #2
// FILE NAME: tail.c
// FILE PURPOSE:
// Пограмата трябва да се реализира стандартната UNIX команда tail.
// Командата tail се използва за показване(на стандартния изход) на
// последните 10 реда на файлове подадени като аргументи.
// Ако са подадени повече от един файлове преди всяко изписване на
// 10-те реда се изобразява заглавен ред със съответното име.
// Функцията трябва да може да чете от стандартния вход при 
// подаване на аргумент "-".
//------------------------------------------------------------------------

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdarg.h>

//------------------------------------------------------------------------
// FUNCTION: tail
// функцията чете един параметър(име на файл), отваря файла за четене,
// след което чете и принтира на стандартния изход само последните
// 10 реда от файла, а ако те са по малко от 10 изписва всичките.
// PARAMETERS:
// 		char * file_name - името на файла който трябва да се прочете.
// 		int arg_c - броят на аргументите за да знаем дали да изписваме
//		  заглавния ред.
//		int cur_line - показва дали сме на първия успешен
//		  ред(без да сме получили грешка) или не, с което ще разбираме
//		  дали да пишем нов ред.
//------------------------------------------------------------------------

int tail(char *, int, int);

//------------------------------------------------------------------------
// FUNCTION: stdin_write
// функцията чете редове от стандартния вход и пише на стандартния 
// изход последните 10 реда, ако са по-малко от 10 изписва всичките.
// PARAMETERS:
// 		char * std_i - този пойнтер винаги има стойност "stdandard out"
//		  за да знаем с какъв параметър да извикаме функцията head.
//		int arg_c - броят на аргументите за да знаем дали да изписваме
//		  заглавния ред.
//		int cur_line - показва дали сме на първия успешен
//		  ред(без да сме получили грешка) или не, с което ще разбираме
//		  дали да пишем нов ред.
//------------------------------------------------------------------------

int stdin_write(char*, int, int);

//------------------------------------------------------------------------
// FUNCTION: head
// функцията чете един параметър(име на мястото от където се взимат данните(стандартния вход или файл)) и го изписва на стандартния изход като заглавен ред със определените визуални елементи("==> "  и " <==");
// PARAMETERS:
// 	char * name -  името на файла на който ще се изпълнява функцията tail.
//  int cur_line - показва дали сме на първия успешен
//		  ред(без да сме получили грешка) или не, с което ще разбираме
//		  дали да пишем нов ред.
//------------------------------------------------------------------------

int head(char *, int);

int main(int argc, char **argv) {
	int stdin_result = -1;
	int tail_result = -1;
	int first_noerr = 1;
	
	if(argc == 1) {
		stdin_result = stdin_write("standard input", argc, first_noerr);
	}
	
	for(int i = 1; i < argc; i++) {
		if(first_noerr == 0) {
			first_noerr = i;
		}
		if(argv[i][0] == '-' && argv[i][1] == '\0') {
			stdin_result = stdin_write("standard input", argc, first_noerr);
		} else {
			tail_result = tail(argv[i], argc, first_noerr);
		}
		if(stdin_result == 0 || tail_result == 0) {
			first_noerr = 0;
		}
	}

	return 0;
}

int tail(char *file_name, int arg_c, int cur_line) {
	int fd = open(file_name, O_RDONLY);
	if(fd < 0) {
		char *message = (char *) malloc(strlen("tail: cannot open '") + strlen(file_name) + strlen("' for reading"));
		strcat(message, "tail: cannot open '");
		strcat(message, file_name);
		strcat(message, "' for reading");
		perror(message);
		free(message);
		return 1;
	}
	
	if(arg_c > 2) {
		head(file_name, cur_line);
	}
	
	char buf[1];
	
	int file_size = lseek(fd,-1 , SEEK_END);
	int new_lines = 0;
	int cur = 1;
	while(new_lines < 11) {
		int read_result = read(fd, buf, 1);
		if(read_result < 0) {
			char *message = (char *) malloc(strlen("tail: error reading '") + strlen(file_name) + 1);
			strcat(message, "tail: error reading '");
			strcat(message, file_name);
			strcat(message, "\'");
			perror(message);
			free(message);
			return 5;
		}
		if(*buf == '\n') {
			new_lines++;
		}
		if(new_lines < 11) {
			cur = lseek(fd, -2, SEEK_CUR);
		}
		if(cur <= 0) {
			break;
		}
	}
	int counter = cur;
	while(counter < file_size) {
		int read_result = read(fd, buf, 1);
		if(read_result < 0) {
			char *message = (char *) malloc(strlen("tail: error reading '") + strlen(file_name) + 1);
			strcat(message, "tail: error reading '");
			strcat(message, file_name);
			strcat(message, "\'");
			perror(message);
			free(message);
			return 3;
		} else if(read_result == 0) {
			continue;
		}
		
		int write_result = write(STDOUT_FILENO, buf, 1);
		if(write_result < 0) {
			perror("tail: error writing");
			return 4;
		} else if(write_result == 0) {
			lseek(fd, -1, SEEK_CUR);
			continue;
		}
		counter++;
	}

	if(new_lines < 11) {
		int write_result = write(STDOUT_FILENO, "\n", 1);
		if(write_result < 0) {
			perror("tail: error writing");
			return 6;
		}
	}

	if(close(fd) < 0) {
		char *message = (char *) malloc(strlen("tail: error reading '") + strlen(file_name) + 1);
		strcat(message, "tail: error reading '");
		strcat(message, file_name);
		strcat(message, "\'");
		perror(message);
		free(message);
		return 2;
	
	}
	return 0;
}

int stdin_write(char *std_i, int arg_c, int cur_line) {
	if(arg_c > 2) {
		head(std_i, cur_line);
	}

	char *input = malloc(10);
	int elements = 0;
	char tmp[1];
	int read_result;
	while(read_result = read(STDIN_FILENO, tmp, 1) != 0) {
		if(read_result < 0) {
			perror("tail: error reading");
			return 2;
		}
		if(elements % 10 == 0) {
			input = realloc(input, elements + 10);
		}
		input[elements++] = *tmp;
	}	
	int new_lines = 0;
	int cur = 0;
	for(cur = elements - 1; cur > 0 && new_lines < 11; cur--) {
		if(*(input + cur) == '\n') {
			new_lines++;
		}
	}
	if(new_lines == 11) {
		cur += 2;
	}
	
	int lines = 0;
	for(int i = cur; i < elements; i++) {
		int write_result = write(STDOUT_FILENO, input + i,  1);
		if(write_result < 0) {
			perror("tail: error writing");
			return 1;
		} else if(write_result == 0) {
			i--;			
			continue;
		}
		if(*(input + i) == '\n') {
			lines++;
		}
	}
	
	return 0;
}

int head(char *name, int cur_line) {
	if(cur_line != 1) {
		write(STDOUT_FILENO, "\n", 1);
	}
	char *header = (char *) malloc(strlen(name) + 9);
	strcat(header, "==> ");
	strcat(header, name);
	strcat(header, " <==\n");
	int write_result = write(STDOUT_FILENO, header, strlen(header));
	if(write_result < 0) {
		return 1;
	}
	free(header);
	
	return 0;
}
