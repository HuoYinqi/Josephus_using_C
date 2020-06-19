#include <stdio.h>
#include <stdlib.h>

#include "src/read_file.h"
#include "src/person.h"
#include "src/josephus.h"

int main()
{
    Reader reader = reader_create();
    reader_set(reader, "data/person.txt");

    string_array_t content;
    string_array_init(content);

    reader_read_file(reader);
    reader_get_content(reader, content);

    Josephus jos = josephus_create();
    josephus_set(jos, 2, 2);

    int line = string_array_size(content);

    for(int i = 0; i < line; i++)
    {
        Person someone = person_create();
        
        const char *s = string_get_cstr(*(string_array_get_at(content, i)));
        person_set_from_string(s, someone);

        char *name = person_get_name(someone);
        int age = person_get_age(someone);
        printf("name: %s\tage: %d\n", name, age);

        josephus_append(jos, someone);
    }

    string_array_clear(content);

    // josephus_pop(jos, 1);

    Person *result = malloc(200);

    josephus_get_result(jos, result);

    int size = josephus_size(jos);

    printf("--------result--------\n");
    for(int i = 0; i < size; i++)
    {   
        char *name = person_get_name(result[i]);
        int age = person_get_age(result[i]);
        printf("name: %s\tage: %d\n", name, age);
    }

    josephus_destroy(jos);
    reader_destroy(reader);
    free(result);
    return 0;
}