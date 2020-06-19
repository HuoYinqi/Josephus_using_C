#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "josephus.h"
#include "person.h"

#define MAX 100
#define SUCCESS 0
#define INVALID_VALUE -1
#define APPEND_FIALED -2

struct Josephus
{
    int start;
    int step;
    person_array_t people;
};

Josephus josephus_create(void)
{
    Josephus self = malloc(sizeof(struct Josephus));
    return self;
}

void josephus_init(Josephus self)
{
    person_array_init(self->people);
}

void josephus_destroy(Josephus self)
{
    for(int i = 0; i < josephus_size(self); i++)
    {
        person_destroy(*(person_array_get_at(self->people, i)));
    } //??

    person_array_clear(self->people);
    free(self);
}

int josephus_set(Josephus self, int start, int step)
{
    if(start < 1)
    {
        return INVALID_VALUE;
    }
    
    if (step < 1)
    {
        return INVALID_VALUE; 
    }

    self->start = start;
    self->step = step;
    
    return SUCCESS;
}

int josephus_set_start(Josephus self, int start)
{
    if(start < 1)
    {
        return INVALID_VALUE;
    }
    self->start = start;

    return SUCCESS;
}

int josephus_set_step(Josephus self, int step)
{
    if (step < 1)
    {
        return INVALID_VALUE; 
    }
    self->step = step;

    return SUCCESS;
}

int josephus_get_result(Josephus self, Person *result)
{
    int size = person_array_size(self->people);
    int nums[MAX];
    for (int i = 0; i < size; i++)
    {
        nums[i] = 1; 
    }   

    int index = self->start - 1;
    for (int i = 0; i < size; i++)
    {
        int valid_step = 0;
        int current_step = 0;
        int current_id = 0;
        while (valid_step < self->step)
        {
            current_id = (index + current_step) % size;
            if (nums[current_id] != 0)
            {
                valid_step++;
            }
            current_step++;
        }

        nums[current_id] = 0;
        result[i] = *(person_array_get(self->people, current_id));
        index = (current_id + 1) % size;
    }
    return SUCCESS;
}

int josephus_append(Josephus self, Person someone)
{
    if(person_array_size(self->people) == MAX)
    {
        return APPEND_FIALED;
    }

    person_array_push_back(self->people, someone);

    return SUCCESS;
}

int josephus_pop(Josephus self, int index)
{
    if(index >= person_array_size(self->people) || index < 0)
    {
        return INVALID_VALUE;
    }

    person_destroy(*(person_array_get_at(self->people, index)));
    person_array_pop_at(NULL, self->people, index);

    return SUCCESS;
}

int josephus_size(Josephus self)
{
    return person_array_size(self->people);
}