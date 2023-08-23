#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
#include <sys/wait.h>

int isatty(int fd);
void reverse_string(char *s);
void prompter(char **argument_count, char **environment);
pid_t fork(void);

#endif