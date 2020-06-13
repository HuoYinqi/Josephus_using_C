#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "josephus.h"
#include "person.h"

#define MAX 100
#define SUCCESS 1
#define FALSE 0
#define INVALID_START -1
#define INVALID_STEP -2
#define INVALID_NUMBER -3

int josephus_new(Josephus *self, int start, int step, int number)
{
    if(start < 1 || start > number)
    {
        return INVALID_START;
    }
    
    else if (step < 1)
    {
        return INVALID_STEP; 
    }

    else if(number < 1 || number > MAX)
    {
        return INVALID_NUMBER;
    }

    self->start = start;
    self->step = step;
    self->number = number;
    self->people = malloc(MAX * sizeof(Person));
    
    return SUCCESS;
}

void josephus_destroy(Josephus* self)
{
    free(self->people);
}

int josephus_put_people(Josephus *self, Person *people)
{
    for (int i = 0; i < (self->number); i++)
    {
        self->people[i] = people[i];
    }
    return SUCCESS;
}

int josephus_get_result(Josephus *self, Person *result)
{
    int size = self->number;
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
        int current_id;
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
        result[i] = self->people[current_id];
        index = (current_id + 1) % size;
    }
    return SUCCESS;
}

int josephus_append(Josephus* self, Person someone)
{
    if(self->number == MAX)
    {
        return FALSE;
    }
    self->people[self->number] = someone;
    self->number ++;
    return SUCCESS;
}

int josephus_pop(Josephus* self, int index)
{
    if(index >= self->number || index < 0)
    {
        return FALSE;
    }

    for(int i = index; i < self->number - 1; i++)
    {
        self->people[i] = self->people[i+1];
    }
    self->number --;
    return SUCCESS;
}