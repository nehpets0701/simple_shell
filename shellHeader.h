#ifndef _shellHeader_H_
#define _shellHeader_H_

/*headers*/
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>

/*functions*/
int main(int argc, char **argv, char **env);
void executeProg(char **argv, char **env);
void executeBuiltin(char **argv);
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *p);
char **ShellStrtok(char *str, char *delim);
char *_strcpy(char *src, char *dest);
int _putchar(char c);
void _puts(char *str);
#endif
