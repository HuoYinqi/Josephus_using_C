#include <stdio.h>
#include <stdlib.h>

#include "src/reader.h"
#include "src/person.h"
#include "src/josephus.h"

int main()
{
    Josephus jos = josephus_create();
    josephus_init(jos, 2, 2);

    char reader[READER_MAX];
    FILE *fp = fopen("data/person.txt", "r");
    if(fp == NULL)
    {
        printf("Open file failed\n");
        return 0;
    }

    //append people in jos
    while(reader_set_from_file(reader, fp) != READER_OVER)
    {
        Person someone = person_create();
        person_set_from_reader(someone, reader);
        josephus_append(jos, someone);
    }

    Person *people = malloc(josephus_size(jos) * sizeof(Person));

    josephus_get_people(jos, people);
    printf("--------people--------\n");
    //print original people in josephus
    for(int i = 0; i < josephus_size(jos); i++)
    {   
        char *name = person_get_name(people[i]);
        int age = person_get_age(people[i]);
        printf("name: %s\tage: %d\n", name, age);
    }

    // pop someone in jos
    Person *pop_one = malloc(sizeof(Person));
    josephus_pop(jos, pop_one, 2);
    printf("\npop -> name: %s\tage: %d\n", person_get_name(*pop_one), person_get_age(*pop_one));
    person_destroy(*pop_one);
    free(pop_one);


    josephus_get_result(jos, people);
    printf("--------result--------\n");
    printf("start: %d\tstep: %d\n", josephus_get_start(jos), josephus_get_step(jos));
    //print people after sort by josephus
    for(int i = 0; i < josephus_size(jos); i++)
    {   
        char *name = person_get_name(people[i]);
        int age = person_get_age(people[i]);
        printf("name: %s\tage: %d\n", name, age);
    }

    josephus_destroy(jos);
    free(people);
    return 0;
}