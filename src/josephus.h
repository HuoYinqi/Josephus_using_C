#ifndef __JOSEPHUS_H__
#define __JOSEPHUS_H__

#include "person.h"

#define JOSEPHUS_MAX_CAPACITY 100
#define JOSEPHUS_APPEND_FAILED -1

typedef struct Josephus *Josephus;

Josephus josephus_create(void);

void josephus_destroy(Josephus);

int josephus_init(Josephus, int start, int step);

int josephus_set_start(Josephus, int start);

int josephus_set_step(Josephus, int step);

int josephus_get_result(Josephus, Person *result);

int josephus_append(Josephus, Person);

int josephus_pop(Josephus, Person*, int index);

int josephus_size(Josephus);

#endif