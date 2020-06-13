#ifndef PERSON_H
#define PERSON_H

typedef struct person
{
    char *name;
    int age;
}Person;

void person_new(Person*);

void person_destroy(Person*);

int person_init(Person*, char *name, int age);

int person_get_info(Person*, char *info);

int person_create_from_string(char *s, Person*);

#endif