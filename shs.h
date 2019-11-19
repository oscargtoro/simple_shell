#ifndef SHS_H_INCLUDED
#define SHS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>

typedef struct stat_s{
	char *data;
	struct stat_s *next;
}stat_t;
void _ntty(char *);
void _itty(char *);
void _read(char **);
char *_getenv(char *);
int _findcmd(char **, char *);

#endif
