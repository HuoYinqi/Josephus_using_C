#ifndef __PERSON_H__
#define __PERSON_H__

typedef struct Person* Person;

Person person_create(void);

void person_destroy(Person);

int person_init(Person, const char *name, int age);

int person_set_name(Person, const char *name);

int person_set_age(Person, int age);

int person_get_age(Person);

char* person_get_name(Person);

int person_set_from_string(Person, const char *s);

#endif