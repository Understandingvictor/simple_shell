#ifndef MAIN_H
#define MAIN_H
#define buffersize 1024
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
void executeCommand(char **arguments);
char *interactiveMode(void);
char **process(char *command);
#endif
