#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int isatty(int fd);
void reverse_string(char *s);
void prompter(char **argument_count, char **environment);
pid_t fork(void);
char *strtok(char *str, const char *delim);
char *strtok_r(char *str, const char *delim, char **saveptr);
int execve(const char *pathname, char *const argv[],
char *const envp[]);

#endif
