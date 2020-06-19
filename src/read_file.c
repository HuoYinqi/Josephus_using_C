#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_file.h"

#define SUCCESS 0
#define OPEN_FILE_FAILED -1

struct Reader
{
    char path[100];
    string_array_t  content; 
};

Reader reader_create(void)
{
    Reader self = malloc(sizeof(struct Reader));
    return self;
}

void reader_init(Reader self)
{
    string_array_init(self->content);
}

void reader_set(Reader self, char* path)
{
    strcpy(self->path, path);
}

void reader_destroy(Reader self)
{
    string_array_clear(self->content);
    free(self);
}

int reader_read_file(Reader self)
{
    FILE *fp = fopen(self->path, "r");
    if(fp == NULL)
    {
        return OPEN_FILE_FAILED;
    }

    string_t line;
    string_init(line);
    while(string_fgets(line, fp, STRING_READ_PURE_LINE))
    {
        string_array_push_back(self->content, line); 
    }

    string_clear(line);
    fclose(fp);
    return SUCCESS;
}

int reader_get_content(Reader self, string_array_t content)
{
    string_array_set(content, self->content);
}