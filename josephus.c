#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "josephus.h"
#include "person.h"

Josephus create_josephus(int start, int step, int number)
{
    Josephus jos = {start, step, number};
    jos.people = malloc(number * sizeof(Person));
    return jos;
}

void put_people_in_josephus(Josephus *self, Person *people)
{
    for (int i = 0; i < (self->number); i++)
    {
        self->people[i] = people[i];
    }
}

Person *get_result(Josephus *self)
{
    int size = self->number;
    int nums[size];
    Person *result = malloc(size * sizeof(Person));
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
    free(self->people);
    return result;
}