#ifndef MYLIB_H
#define MYLIB_H


#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <linux/limits.h>
#include <string.h>
#include <sys/stat.h>

int walk(const char *dirname, int do_dirs, const char *searchf);

#endif