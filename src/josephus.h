#ifndef JOSEPHUS_H
#define JOSEPHUS_H

#include "person.h"

typedef struct Josephus
{
    int start;
    int step;
    int number;
    Person *people;
} Josephus;

int josephus_new(Josephus *self, int start, int step, int number);

void josephus_destroy(Josephus* self);

int josephus_put_people(Josephus *self, Person *people);

int josephus_get_result(Josephus *self, Person *result);

int josephus_append(Josephus*, Person);

int josephus_pop(Josephus*, int index);

#endif