#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>

#define MAX_INPUT_SIZE 1024
#define CHARN 10
#define ERR "check number of arguments passed\n"
#define VALUE "variable does not exist\n"

extern char **environ;

/* main */
int run_interactive_shell(void);
int run_non_interactive_shell(char *inp);

/* comment handler */

/* logical operator handler */

/* handle built ins */
int allbuiltin(char **av, char **env);
void cd_builtin(char **av, char **env);
void myenv(void);
void err(char *av);
void execute_cmd(char **av);
char *exec_new(char **av);
ssize_t gettypro(char **a, char *b, char *c, char *buf_end, size_t *g);
ssize_t getty(char **ptr, size_t *g, FILE *str);
void empty1(char **av);
void empty(char **av, char **env);
char *get_input(void);
char **tok(char *cmd, char *d);
int myenvset(char **av, char **env);
int myenvunset(char **av, char **env);
char *mygetenv(const char *n);
char **createnv(void);
int myvarset(char *av, char *val, char **env);
int mypwd(char **env, char *cur);

/* new strings */

char *mystrcat(char *dest, char *src);
char *alloc(char *lineptr, size_t os, size_t ns);
char *_copy(char *d, char *s, size_t g);
int strcompare(const char *s1, const char *s2);
size_t strlength(const char *str);
char *strduplicate(const char *s);
 char *strcopy(char *dest, const char *src);

/* handle files and arguments */

/* String functions */
char *_strchr(const char *s, int c);
char *_strtok(char *str, const char *delimiters);
int _putchar(char c);
int _puts(const char *s);
#endif
