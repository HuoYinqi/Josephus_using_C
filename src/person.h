#ifndef PERSON_H
#define PERSON_H

typedef struct person
{
    char *name;
    int age;
}Person;

char* get_person_info(Person);

Person str2person(char*);

#endif