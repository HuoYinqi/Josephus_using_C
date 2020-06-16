#ifndef PERSON_H
#define PERSON_H

#include "string.h"

typedef struct Person* Person;

void person_new(Person);

void person_destroy(Person);

int person_init(Person, char *name, int age);

int person_get_info(Person, char *info);

int person_create_from_string(const char *s, Person);

#endif