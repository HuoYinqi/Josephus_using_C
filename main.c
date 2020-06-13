#include <stdio.h>
#include <stdlib.h>

#include "src/person.h"
#include "src/josephus.h"
#include "src/read_file.h"

int main()
{
    Josephus jos;
    Person people[10];
    Person result[10];
    int line = 0;
    for(int i = 0; i < 10; i++)
    {
        person_new(people + i);
    }
    create_people_from_file("data/person.txt", &line, people);
    josephus_new(&jos, 1, 2, 7);
    josephus_put_people(&jos, people);
    josephus_get_result(&jos, result);
    for(int i = 0; i < jos.number; i++)
    {
        char info[100];
        person_get_info(result + i, info);
        printf("%s\n", info);
    }
    
    for(int i = 0; i < 10; i++)
    {
        person_destroy(people + i);
    }
    josephus_destroy(&jos);

    return 0;

}