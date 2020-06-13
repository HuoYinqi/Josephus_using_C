#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "person.h"

#define SUCCESS 1
#define FALSE 0

void person_new(Person* self)
{
    self->name = malloc(20);
}

void person_destroy(Person *self)
{
    free(self->name);
}

int person_init(Person* self, char *name, int age)
{
    strcpy(self->name, name);
    if(age < 1 || age > 100)
    {   
        return FALSE;
    }
    self->age = age;
    return SUCCESS;
}

int person_get_info(Person *self, char *info)
{
    char name[10];
    char age[10];
    strcpy(info, "name: ");
    strcat(info, self->name);
    strcat(info, "\tage: ");
    itoa(self->age, age, 10);
    strcat(info, age);
    return SUCCESS;
}

int person_create_from_string(char *s, Person *self)
{
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
            return FALSE;
        }
    }
    for (int i = 0; i < split_index; i++)
    {
        self->name[i] = s[i];
    }

    for (int i = 0; i < strlen(s) - split_index - 1; i++)
    {
        age[i] = s[i + split_index + 1];
    }
    self->age = atoi(age);
    return SUCCESS;
}