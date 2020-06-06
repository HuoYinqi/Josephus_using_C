#ifndef __josephus_h__
#define __josephus_h__

#include "person.h"

typedef struct Josephus
{
    int start;
    int step;
    int number;
    Person *people;
} Josephus;

Josephus create_josephus(int start, int step, int number);

void put_people_in_josephus(Josephus*, Person*);

Person* get_result(Josephus*);


#endif