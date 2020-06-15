#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "read_file.h"

#define SUCCESS 1
#define FALSE 0
#define OPEN_FILE_FAILED -1

int create_people_from_file(char* path, int* line, Person *people)
{   
    int i = 0;
    char buff[255];
    FILE *fp = fopen(path, "r");

    if(fp == NULL)
    {
        return OPEN_FILE_FAILED;
    }

    while(fgets(buff, 256, fp) != NULL)
    {
        if(person_create_from_string(buff, people + i) == 0)
        {
            return FALSE;
        }
        i++;
    }
    *line = i;
    fclose(fp);
    return SUCCESS;
}
