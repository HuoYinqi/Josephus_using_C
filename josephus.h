#ifndef JOSEPHUS_H
#define JOSEPHUS_H

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