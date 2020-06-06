#include <stdio.h>
#include <stdlib.h>

#include "read_file.h"

Person *create_people_from_file(char* path, int* line)
{
    FILE *fp;
    Person *people;
    people = malloc(10 * sizeof(Person));
    char buff[255];
    fp = fopen(path, "r");
    if(fp == NULL)
    {
        return NULL;
    }
    int i = 0;
    while(fgets(buff, 256, fp) != NULL)
    {
        people[i] = str2person(buff);
        i++;
    }
    *line = i;
    fclose(fp);
    return people;
}
