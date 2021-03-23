#ifndef _MYLOG_H_
#define _MYLOG_H_

#include <stdio.h>
#include <time.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define FATALERR (1 << 0)
#define ERROR	(1 << 1)
#define WARNING (1 << 2)
#define INFO	(1 << 3)
#define DEBUG	(1 << 4)

void LOG(int level,char *s,int fd);
int SetLogLevel(int level);

#endif
