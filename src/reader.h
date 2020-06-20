#ifndef __READER_H__
#define __READER_H__

#include <stdio.h>

#define READER_MAX 30
#define READER_OVER -1

extern char reader[READER_MAX];

int reader_set_from_file(char *reader, FILE*);

#endif