#ifndef READ_FILE_H
#define READ_FILE_H

#include "m-array.h"
#include "m-string.h"

ARRAY_DEF(string_array, string_t);

typedef struct Reader* Reader;

void reader_init(Reader, char *path);

void reader_destroy(Reader);

int reader_read_file(Reader);

int reader_get_content(Reader, string_array_t content);

#endif