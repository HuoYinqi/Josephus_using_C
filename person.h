#ifndef __person_h__
#define __person_h__

typedef struct Person
{
    char *name;
    int age;
} Person;

char* get_person_info(Person);

Person str2person(char*);

#endif