#include "error.h"
#include "reader.h"

int reader_set_from_file(char *reader, FILE *fp)
{
    if(fgets(reader, READER_MAX, fp) != NULL)
    {
        return SUCCESS;
    }
    return READER_OVER;
}