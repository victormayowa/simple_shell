#ifndef MY_HEADER_FILE_H
#define MY_HEADER_FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

#define MAX_INPUT_SIZE 1024
/* run modes */
void run_interactive_shell();
void run_non_interactive_shell();
void read_input(char *input);

#endif
