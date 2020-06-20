#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "error.h"
#include "josephus.h"
#include "person.h"
#include "../include/m-array.h"

ARRAY_DEF(person_array, Person, M_POD_OPLIST)

struct Josephus
{
    int start;
    int step;
    person_array_t people;
};

Josephus josephus_create(void)
{
    Josephus self = malloc(sizeof(struct Josephus));
    if(self == NULL)
    {
        return ALLOCATE_MEMORY_FAILED;
    }

    person_array_init(self->people);
    if(self->people == NULL)
    {
        return ALLOCATE_MEMORY_FAILED;
    }

    return self;
}

void josephus_destroy(Josephus self)
{
    for(int i = 0; i < josephus_size(self); i++)
    {
        person_destroy(*(person_array_get_at(self->people, i)));
    } 

    person_array_clear(self->people);
    free(self);
}

int josephus_init(Josephus self, int start, int step)
{
    if(start < 1 || step < 1)
    {
        return INVALID_ARGV;
    }

    self->start = start;
    self->step = step;
    
    return SUCCESS;
}

int josephus_set_start(Josephus self, int start)
{
    if(start < 1)
    {
        return INVALID_ARGV;
    }
    self->start = start;

    return SUCCESS;
}

int josephus_set_step(Josephus self, int step)
{
    if (step < 1)
    {
        return INVALID_ARGV; 
    }
    self->step = step;

    return SUCCESS;
}

int josephus_get_result(Josephus self, Person *result)
{
    person_array_t temp;
    person_array_init_set(temp, self->people);
    
    int size = person_array_size(temp);
    int current_id = self->start - 1;

    for (int i = 0; i < size; i++)
    {
        current_id = (current_id + self->step - 1) % person_array_size(temp);

        result[i] = *(person_array_get(temp, current_id));
        person_array_pop_at(NULL, temp, current_id);
    }

    person_array_clear(temp);
    return SUCCESS;
}

int josephus_append(Josephus self, Person someone)
{
    if(person_array_size(self->people) == JOSEPHUS_MAX_CAPACITY)
    {
        return JOSEPHUS_APPEND_FAILED;
    }

    person_array_push_back(self->people, someone);

    return SUCCESS;
}

int josephus_pop(Josephus self, Person *someone, int index)
{
    if(index >= person_array_size(self->people) || index < 0)
    {
        return INVALID_ARGV;
    }

    person_array_pop_at(someone, self->people, index);

    return SUCCESS;
}

int josephus_size(Josephus self)
{
    return person_array_size(self->people);
}