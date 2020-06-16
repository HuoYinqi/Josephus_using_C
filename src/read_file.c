#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_file.h"

#define SUCCESS 1
#define FALSE 0
#define OPEN_FILE_FAILED -1

struct Reader
{
    char path[100];
    string_array_t  content; 
};

void reader_init(Reader self, char* path)
{
    strcpy(self->path, path);
    string_array_init(self->content);
}

void reader_destroy(Reader self)
{
    string_array_clear(self->content);
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