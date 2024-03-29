#ifndef SHS_H_INCLUDED
#define SHS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

extern char **environ;

void _ntty(char *, pid_t);
void _itty(char *, pid_t);
void _exec(char *, char **, char *, int *);
void _itoa(int, char *);
int _atoi(char *);
ssize_t _read(char **, char **, int *, char *, char *);
void trimspaces(char **);
char *_getenv(char *);
void ecodeinit(char **);
int _findcmd(char **, char *);
char *token_command(char *);
char **token_arguments(char *, char *, char *);
void itty_free(char *, char **, char *);
void ntty_free(char **, char *);
int _getpath(char **, char *);
void pdeniederr(char *, char *);
void nfounderr(char *, char *);
int _strcmp(char *, char *);
int _strlen(char *);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);
char *_strdup(char *);
void freepcontent(char **);
void trimcomments(char **);
void trimexit(char **pinput, char **env, char *exit_c);
void mpidinit(char **, pid_t);

#endif
