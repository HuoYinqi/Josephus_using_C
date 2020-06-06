#include <stdio.h>
#include "josephus.h"
#include "read_file.h"
// #include "person.h"

int main()
{
    int line;
    int start, step;
    Person *people = create_people_from_file("data\\person.txt", &line);
    for (int i = 0; i < line; i++)
    {
        printf("%s\n", get_person_info(people[i]));
    }

    start = 1;
    step = 2;

    Josephus jos = create_josephus(start, step, line);
    put_people_in_josephus(&jos, people);
    Person *result = get_result(&jos);
    printf("----------------\n");
    for (int i = 0; i < line; i++)
    {
        printf("%s\n", get_person_info(result[i]));
    }

    return 0;
}
