#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "error.h"
#include "person.h"

struct Person{
    char *name;
    int age;
};

Person person_create(void)
{
    Person self = malloc(sizeof(struct Person));
    if(self == NULL)
    {
        return ALLOCATE_MEMORY_FAILED;
    }

    self->name = malloc(20);
    if(self->name == NULL)
    {
        return ALLOCATE_MEMORY_FAILED;
    }  

    return self;
}

void person_destroy(Person self)
{
    free(self->name);
    free(self);
}

int person_init(Person self, const char *name, int age)
{
    if(age < 1 || age > 100)
    {   
        return INVALID_ARGV;
    }
    self->age = age;
    strcpy(self->name, name);
    
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
        return INVALID_ARGV;
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

int person_set_from_string(Person self, const char *s)
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
            return INVALID_ARGV;
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
        return INVALID_ARGV;
    }

    return SUCCESS;
}
