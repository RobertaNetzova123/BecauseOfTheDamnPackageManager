
//------------------------------------------------------------------------
// NAME: Ивона Мирчева
// CLASS: XIб
// NUMBER: 10
// PROBLEM: #1
// FILE NAME: shell.c (unix file name)
// FILE PURPOSE: Да се реализира прост команден интерпретатор shell.
//------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

#define BUFSIZE 1000

//------------------------------------------------------------------------
// FUNCTION: error_message
// Приема файла предизвикал грешка и изкарва дадено съобщение със:
// съответното съдържание на грешката и името на файла, заради който е извикана
// PARAMETERS:
// pid - процеса, който ще се убие
// exec - Изпълнимия файл дал грешка
//------------------------------------------------------------------------
void error_message(pid_t pid, char *exec);

//------------------------------------------------------------------------
// FUNCTION: execute_the_line
// Създава процес и изпълнява подадения ред от стандартния вход
// PARAMETERS:
// argv - низ от процесите, които трябва да се изпълнят
//------------------------------------------------------------------------
int execute_the_line(char *argv[]);

//------------------------------------------------------------------------
// FUNCTION: parse_cmdline
// Приема ред от стандартния вход под формата на низ и връща масив от низове,
// готови да се подадат на execv(const char *filename, char *const argv[]);
// PARAMETERS:
// cmdline - Подаден ред от стандартния вход
//------------------------------------------------------------------------
char **parse_cmdline(const char *cmdline) ;


int main() {
  char *buffer = (char *)calloc(BUFSIZE, sizeof(char));
  char **parsed_cmdline;
  printf("$ ");
  // while (!feof(stdin) && getline(&buffer, &bufsize, stdin) != EOF) {
  while (fgets(buffer, BUFSIZE, stdin) != NULL) {
    parsed_cmdline = parse_cmdline(buffer);
    free(buffer);
    buffer = NULL;
    execute_the_line(parsed_cmdline);
    buffer = (char *)calloc(BUFSIZE, sizeof(char));
    printf("$ ");
  }
  exit(EXIT_SUCCESS);
  return 0;
}

char **parse_cmdline(const char *cmdline) {
  char **parsed_cmdline = (char **)calloc(BUFSIZE, sizeof(char *));
  if (parsed_cmdline == NULL) {
    // perror("Unable to allocate");
    exit(EXIT_FAILURE);
  }
  char *buffer = (char *)calloc(BUFSIZE, sizeof(char));
  if (buffer == NULL) {
    // perror("Unable to allocate");
    exit(EXIT_FAILURE);
  }
  parsed_cmdline[0] = (char *)calloc(BUFSIZE, sizeof(char));
  if (parsed_cmdline[0] == NULL) {
    // perror("Unable to allocate");
    exit(EXIT_FAILURE);
  }
  char how_to_break = 0;
  int i = 0;

  for (int bufcount = 0, j = 0; cmdline[j - 1] != '\n'; j++, bufcount++) {
    buffer[bufcount] = cmdline[j];
    if (buffer[bufcount] == ' ' || (how_to_break = buffer[bufcount]) == '\n') {
      buffer[bufcount] = 0; //Removes space/ newline
      strcat(parsed_cmdline[i], buffer);
      i++;
      parsed_cmdline[i] = (char *)calloc(BUFSIZE, sizeof(char));
      if (how_to_break == '\n') break;
      bufcount = -1;
      free(buffer);
      buffer = NULL;
      buffer = (char *)calloc(BUFSIZE, sizeof(char));
    }
  }
  parsed_cmdline[i] = NULL; //So it will be sutable for execv
  free(buffer);
  buffer = NULL;
  return parsed_cmdline;
}

int execute_the_line(char *argv[]) {
  pid_t pid = fork();
  if (pid < 0) {
    error_message(pid, "fork");
  } else if (pid == 0) {
    if (execv(argv[0], argv) == -1) {
      error_message(pid, argv[0]);
    }
    exit(EXIT_SUCCESS);  // Fixed CTRL+D
  } else if (pid > 0)
    if (waitpid(-1, NULL, 0) == -1)
      error_message(pid, argv[0]);

  return 0;
}

void error_message(pid_t pid, char *exec) {
  perror(exec);
  exit(EXIT_FAILURE);
}
// For future use
// // int pipe( int filedesc[2] );
// // int dup2( int old, int new );

