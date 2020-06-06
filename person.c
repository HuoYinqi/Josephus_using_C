#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "person.h"

char *get_person_info(Person someone)
{
    char *info = malloc(100);
    char name[10];
    strcpy(info, "name: ");
    strcat(info, someone.name);
    strcat(info, "\tage: ");
    char age[10];
    itoa(someone.age, age, 10);
    strcat(info, age);
    return info;
}

Person str2person(char *s)
{
    Person someone;
    char *name = malloc(10);
    char age[4];
    int split_index;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ',')
        {
            split_index = i;
            break;
        }
        if (i == strlen(s))
        {
            exit(1);
        }
    }
    for (int i = 0; i < split_index; i++)
    {
        name[i] = s[i];
    }

    for (int i = 0; i < strlen(s) - split_index - 1; i++)
    {
        age[i] = s[i + split_index + 1];
    }
    someone.name = name;
    sscanf(age, "%d", &someone.age);
    return someone;
}