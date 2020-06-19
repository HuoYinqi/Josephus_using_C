#ifndef JOSEPHUS_H
#define JOSEPHUS_H

#include "person.h"
#include "../lib/m-array.h"

ARRAY_DEF(person_array, Person, M_POD_OPLIST)

typedef struct Josephus *Josephus;

Josephus josephus_create(void);

void josephus_destroy(Josephus);

int josephus_set(Josephus, int start, int step);

int josephus_set_start(Josephus, int start);

int josephus_set_step(Josephus, int step);

int josephus_get_result(Josephus, Person *result);

int josephus_append(Josephus, Person);

int josephus_pop(Josephus, int index);

int josephus_size(Josephus);

#endif