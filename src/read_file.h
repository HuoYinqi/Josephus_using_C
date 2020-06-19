#ifndef READ_FILE_H
#define READ_FILE_H

#include "m-array.h"
#include "m-string.h"

ARRAY_DEF(string_array, string_t);

typedef struct Reader* Reader;

Reader reader_create(void);

void reader_init(Reader);

void reader_set(Reader, char* path);

void reader_destroy(Reader);

int reader_read_file(Reader);

int reader_get_content(Reader, string_array_t content);

#endif