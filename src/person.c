#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "person.h"

#define SUCCESS 0
#define INVALID_AGE -1
#define INVALID_STRING -2

struct Person{
    char *name;
    int age;
};

Person person_create(void)
{
    Person self = malloc(sizeof(struct Person));
    return self;
}

void person_init(Person self)
{
    self->name = malloc(20);
}

void person_destroy(Person self)
{
    free(self->name);
    free(self);
}

int person_set(Person self, const char *name, int age)
{
    strcpy(self->name, name);
    if(age < 1 || age > 100)
    {   
        return INVALID_AGE;
    }
    self->age = age;
    return SUCCESS;
}

int person_set_name(Person self, const char *name)
{
    strcpy(self->name, name);
    return SUCCESS;
}

int person_set_age(Person self, int age)
{
    if(age < 1 || age > 100)
    {   
        return INVALID_AGE;
    }
    self->age = age;
    return SUCCESS;
}

int person_get_age(Person self)
{
    return self->age;
}

char* person_get_name(Person self)
{
    return self->name;
}

int person_set_from_string(const char *s, Person self)
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
            return INVALID_STRING;
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

    if(self->age < 1 || self->age > 100)
    {   
        return INVALID_AGE;
    }

    return SUCCESS;
}
