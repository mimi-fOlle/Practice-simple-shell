#ifndef _CONCEPT_H
#define _CONCEPT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

pid_t getpid(void);
pid_t getppid(void);
ssize_t getline(char **lines, size_t *n, FILE *stream);
char *strtok(char *str, const char *delim);
int execve(const char *pathname, char *const argv[], char *const envp[]);
#endif
