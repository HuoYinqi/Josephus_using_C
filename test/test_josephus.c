#include <stdlib.h>

#include "cbehave/cbehave.h"
#include "../src/josephus.h"
#include "../src/error.h"
#include "../src/error.h"

FEATURE(1, "Test josephus_init function")  
    Josephus jos = josephus_create();

    SCENARIO("initiate start and step")

        GIVEN("start = 1, step = 2")
        GIVEN_END

        WHEN("We invoke josephus_init function")
            int state = josephus_init(jos, 1, 2);
            int start = josephus_get_start(jos);
            int step = josephus_get_step(jos);
        WHEN_END

        THEN("get state = SUCCESS, start = 1, step = 2")
            SHOULD_INT_EQUAL(state, SUCCESS);
            SHOULD_INT_EQUAL(start, 1);
            SHOULD_INT_EQUAL(step, 2);
        THEN_END
        
    SCENARIO_END

    SCENARIO("initiate invalid start")

        GIVEN("start = -1, step = 2")
        GIVEN_END

        WHEN("We invoke josephus_init function")
            int state = josephus_init(jos, -1, 2);
        WHEN_END

        THEN("get state = INVALID_ARGV")
            SHOULD_INT_EQUAL(state, INVALID_ARGV);
        THEN_END
        
    SCENARIO_END

    SCENARIO("initiate invalid step")

        GIVEN("start = 1, step = 0")
        GIVEN_END

        WHEN("We invoke josephus_init function")
            int state = josephus_init(jos, 1, 0);
        WHEN_END

        THEN("get state = INVALID_ARGV")
            SHOULD_INT_EQUAL(state, INVALID_ARGV);
        THEN_END
        
    SCENARIO_END

    josephus_destroy(jos);
FEATURE_END

FEATURE(2, "Test josephus_set_start function")
    Josephus jos = josephus_create();

    SCENARIO("set start after initiate")
        josephus_init(jos, 1, 1);

        GIVEN("start = 2")
        GIVEN_END

        WHEN("we invoke josephus_set_start function")
            int state = josephus_set_start(jos, 2);
            int start = josephus_get_start(jos);
        WHEN_END

        THEN("get state = SUCCESS, start = 2")
            SHOULD_INT_EQUAL(state, SUCCESS);
            SHOULD_INT_EQUAL(start, 2);
        THEN_END

    SCENARIO_END

    SCENARIO("set start before initiate")

        GIVEN("start = 2")
        GIVEN_END

        WHEN("we invoke josephus_set_start function")
            int state = josephus_set_start(jos, 2);
            int start = josephus_get_start(jos);
        WHEN_END

        THEN("get state = SUCCESS, start = 2")
            SHOULD_INT_EQUAL(state, SUCCESS);
            SHOULD_INT_EQUAL(start, 2);
        THEN_END

    SCENARIO_END

    SCENARIO("set invalid start")
    
        GIVEN("start = 0")
        GIVEN_END

        WHEN("we invoke josephus_set_start function")
            int state = josephus_set_start(jos, 0);
            int start = josephus_get_start(jos);
        WHEN_END

        THEN("get state = INVALID_ARGV")
            SHOULD_INT_EQUAL(state, INVALID_ARGV);
        THEN_END

    SCENARIO_END

    josephus_destroy(jos);
FEATURE_END

FEATURE(3, "Test josephus_set_step function")
    Josephus jos = josephus_create();

    SCENARIO("set step after initiate")
        josephus_init(jos, 1, 1);

        GIVEN("step = 2")
        GIVEN_END

        WHEN("we invoke josephus_set_step function")
            int state = josephus_set_step(jos, 2);
            int step = josephus_get_step(jos);
        WHEN_END

        THEN("get state = SUCCESS, step = 2")
            SHOULD_INT_EQUAL(state, SUCCESS);
            SHOULD_INT_EQUAL(step, 2);
        THEN_END

    SCENARIO_END

    SCENARIO("set start before initiate")

        GIVEN("step = 2")
        GIVEN_END

        WHEN("we invoke josephus_set_start function")
            int state = josephus_set_step(jos, 2);
            int step = josephus_get_step(jos);
        WHEN_END

        THEN("get state = SUCCESS, start = 2")
            SHOULD_INT_EQUAL(state, SUCCESS);
            SHOULD_INT_EQUAL(step, 2);
        THEN_END

    SCENARIO_END

    SCENARIO("set invalid step")
    
        GIVEN("step = 0")
        GIVEN_END

        WHEN("we invoke josephus_set_step function")
            int state = josephus_set_step(jos, 0);
            int step = josephus_get_step(jos);
        WHEN_END

        THEN("get state = INVALID_ARGV")
            SHOULD_INT_EQUAL(state, INVALID_ARGV);
        THEN_END

    SCENARIO_END

    josephus_destroy(jos);
FEATURE_END

FEATURE(4, "Test josephus_append function and josephus_pop function")
    Josephus jos = josephus_create();
    Person *people = malloc(200);
    int size = 0;
    int state = 0;

    SCENARIO("add person in empty josephus ring")

        GIVEN("first person : Bob, 12")
            Person someone_1 = person_create();
            person_init(someone_1, "Bob", 12);
        GIVEN_END

        WHEN("we invoke josephus_append function")
            state = josephus_append(jos, someone_1);
            josephus_get_people(jos, people);
            size = josephus_size(jos);
        WHEN_END

        THEN("first element in people should be someone_1(Bob, 12), state = SUCCESS, size = 1")
            SHOULD_INT_EQUAL(state, SUCCESS);
            SHOULD_BE_TRUE(person_equal(people[0], someone_1));
            SHOULD_INT_EQUAL(size, 1);
        THEN_END


        GIVEN("second person: Jack, 13")
            Person someone_2 = person_create();
            person_init(someone_2, "Jack", 13);
        GIVEN_END

        WHEN("we invoke josephus_append function")
            state = josephus_append(jos, someone_2);
            josephus_get_people(jos, people);
            size = josephus_size(jos);
        WHEN_END

        THEN("new element in people should be someone_2(Jack, 13), state = SUCCESS, size = 2")
            SHOULD_INT_EQUAL(state, SUCCESS);
            SHOULD_BE_TRUE(person_equal(people[1], someone_2));
            SHOULD_INT_EQUAL(size, 2);
        THEN_END


        GIVEN("invalid pop index(more than size of josephus): 2 ")
            Person *pop_one = malloc(20);
        GIVEN_END

        WHEN("we invoke josephus_pop function")
            state = josephus_pop(jos, pop_one, 2);
            size = josephus_size(jos);
        WHEN_END

        THEN("get state = INVALID_ARGV, size = 2, pop failed")
            SHOULD_INT_EQUAL(state, INVALID_ARGV);
            SHOULD_INT_EQUAL(size, 2);
        THEN_END

        GIVEN("pop index: 0 ")
        GIVEN_END

        WHEN("we invoke josephus_pop function")
            state = josephus_pop(jos, pop_one, 0);
            size = josephus_size(jos);
            josephus_get_people(jos, people);
        WHEN_END

        THEN("get state = SUCCESS, size = 1, *pop_one = someone_1, people[0] = someone_2")
            SHOULD_INT_EQUAL(state, SUCCESS);
            SHOULD_INT_EQUAL(size, 1);
            SHOULD_BE_TRUE(person_equal(*pop_one, someone_1));
            SHOULD_BE_TRUE(person_equal(people[0], someone_2));

            person_destroy(*pop_one);
            free(pop_one);
        THEN_END

    SCENARIO_END

    josephus_destroy(jos);
    free(people);
FEATURE_END

FEATURE(5, "Test josephus_get_result function")
    Josephus jos = josephus_create();
    Person *result = malloc(200);

    Person someone_1 = person_create();
    person_init(someone_1, "aaa", 11);

    Person someone_2 = person_create();
    person_init(someone_2, "bbb", 12);

    Person someone_3 = person_create();
    person_init(someone_3, "ccc", 13);

    josephus_append(jos, someone_1);
    josephus_append(jos, someone_2);
    josephus_append(jos, someone_3);

    SCENARIO("when start more than size of people in josephus ring")

        GIVEN("start = 4")
            josephus_init(jos, 4, 1);
        GIVEN_END

        WHEN("we invoke josephus_get_result function")
            int state = josephus_get_result(jos, result);
        WHEN_END

        THEN("get state = INVALID_ARGV")
            SHOULD_INT_EQUAL(state, INVALID_ARGV);
        THEN_END   

    SCENARIO_END

    SCENARIO("input valid start and step")

        GIVEN("start = 2, step = 2")
            josephus_init(jos, 2, 2);
        GIVEN_END

        WHEN("we invoke josephus_get_result function")
            int state = josephus_get_result(jos, result);
        WHEN_END

        THEN("get state = SUCCESS, and first is someone_3, second is someone_2, third is someone_3")
            SHOULD_INT_EQUAL(state, SUCCESS);
            SHOULD_BE_TRUE(person_equal(result[0], someone_3));
            SHOULD_BE_TRUE(person_equal(result[1], someone_2));
            SHOULD_BE_TRUE(person_equal(result[2], someone_1));
        THEN_END  

        GIVEN("start = 1, step = 2")
            josephus_init(jos, 1, 2);
        GIVEN_END

        WHEN("we invoke josephus_get_result function")
            int state_1 = josephus_get_result(jos, result);
        WHEN_END

        THEN("get state = SUCCESS, and first is someone_3, second is someone_2, third is someone_3")
            SHOULD_INT_EQUAL(state_1, SUCCESS);
            SHOULD_BE_TRUE(person_equal(result[0], someone_2));
            SHOULD_BE_TRUE(person_equal(result[1], someone_1));
            SHOULD_BE_TRUE(person_equal(result[2], someone_3));
        THEN_END  

    SCENARIO_END

    josephus_destroy(jos);
    free(result);
FEATURE_END

int main()
{
    cbehave_feature josephus_features[] = {{feature_idx(1)}, {feature_idx(2)}, {feature_idx(3)}, {feature_idx(4)}, {feature_idx(5)}};
    return cbehave_runner("Josephus Features are as belows:", josephus_features);
}