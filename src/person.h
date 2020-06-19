#ifndef PERSON_H
#define PERSON_H

#include "string.h"

typedef struct Person* Person;

Person person_create(void);

void person_destroy(Person);

int person_set(Person, const char *name, int age);

int person_set_name(Person, const char *name);

int person_set_age(Person, int age);

int person_get_age(Person);

char* person_get_name(Person);

int person_set_from_string(const char *s, Person);

#endif