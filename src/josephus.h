#ifndef JOSEPHUS_H
#define JOSEPHUS_H

#include "person.h"
#include "m-array.h"

ARRAY_DEF(person_array, Person, M_POD_OPLIST)

typedef struct Josephus *Josephus;

int josephus_new(Josephus self, int start, int step);

void josephus_destroy(Josephus self);

int josephus_get_result(Josephus self, Person *result);

int josephus_append(Josephus, Person);

int josephus_pop(Josephus, int index);

int josephus_size(Josephus);

#endif