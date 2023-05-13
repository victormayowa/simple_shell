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

extern char **environ;

/* main */
void read_input(char *input);
int is_interactive(void);
void run_interactive_shell(void);
void run_non_interactive_shell(void);
char **split_input_by_semicolon(const char *input);

/* comment handler */
int is_comment(const char *command);
char *remove_comments(const char *command);

/* logical operator handler */
int is_logical_operator_present(const char *command);
void handle_logical_operator(const char *command);
void execute_command_with_logical_or(const char *command);
void execute_command_with_logical_and(const char *command);
char **split_command_by_logical_operator(const char *cmd, const char* oprt);
void execute_single_command(const char *command);
void handle_logical_operator(const char *command);

void execute_command(const char *command);

/* handle built ins */
int is_builtin_command(const char *command);
void handle_builtin_command(const char *command);
void handle_exit_command(const char *command);
void handle_cd_command(const char *command);
void handle_env_command(const char *command);
void handle_setenv_command(const char *command);
void handle_unsetenv_command(const char *command);
void handle_alias_command(const char *command);

/* handle files and arguments */
char **parse_command_for_filenames(const char *command);
char **parse_command_for_arguments(const char *command);
void execute_external_command(char **arguments, char **filenames);

#endif
