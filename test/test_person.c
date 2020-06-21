#include "cbehave/cbehave.h"
#include "../src/person.h"
#include "../src/error.h"

FEATURE(1, "Test person_init function")
    Person someone = person_create();

    SCENARIO("name and age initial")

        GIVEN("name: Bob, age: 12")      
        GIVEN_END

        WHEN("we invoke person_init function")
            int state = person_init(someone, "Bob", 12);
            char *name = person_get_name(someone);
            int age = person_get_age(someone);
        WHEN_END

        THEN("get state = SUCCESS name = Bob, age = 12")
            SHOULD_INT_EQUAL(state, SUCCESS);
            SHOULD_STR_EQUAL(name, "Bob");
            SHOULD_INT_EQUAL(age, 12);
        THEN_END     

    SCENARIO_END

    SCENARIO("invalid age initial")

        GIVEN("age more than the up bound")      
        GIVEN_END

        WHEN("we invoke person_init function")
            int state = person_init(someone, "Bob", 61);
        WHEN_END

        THEN("get state = INVALID_ARGV")
            SHOULD_INT_EQUAL(state, INVALID_ARGV);           
        THEN_END     

    SCENARIO_END

    SCENARIO("invalid age initial")

        GIVEN("age lower than the up bound")      
        GIVEN_END

        WHEN("we invoke person_init function")
            int state = person_init(someone, "Bob", -1);
        WHEN_END

        THEN("get state = INVALID_ARGV")
            SHOULD_INT_EQUAL(state, INVALID_ARGV);           
        THEN_END     

    SCENARIO_END

    person_destroy(someone);
FEATURE_END

FEATURE(2, "Test person_set_name function")
    Person someone = person_create();

    SCENARIO("reset name after initial")
        person_init(someone, "Bob", 12);

        GIVEN("name: Jack")
        GIVEN_END

        WHEN("we invoke person_set_name function")
            int state = person_set_name(someone, "Jack");
            char *name = person_get_name(someone);
        WHEN_END

        THEN("get state = SUCCESS, name = Jack")
            SHOULD_INT_EQUAL(state, SUCCESS);
            SHOULD_STR_EQUAL(name, "Jack");
        THEN_END
        
    SCENARIO_END

    SCENARIO("reset name before initial")
        
        GIVEN("name: Jack")
        GIVEN_END

        WHEN("we invoke person_set_name function")
            int state = person_set_name(someone, "Jack");
            char *name = person_get_name(someone);
        WHEN_END

        THEN("get state = SUCCESS, name = Jack")
            SHOULD_INT_EQUAL(state, SUCCESS);
            SHOULD_STR_EQUAL(name, "Jack");
        THEN_END
        
    SCENARIO_END
    
    person_destroy(someone);
FEATURE_END

FEATURE(3, "Test person_set_age function")
    Person someone = person_create();

    SCENARIO("reset age after initial")
        person_init(someone, "Bob", 12);    

        GIVEN("age = 20")
        GIVEN_END

        WHEN("we invoke person_set_age function")
            int state = person_set_age(someone, 20);
            int age = person_get_age(someone);
        WHEN_END

        THEN("get state = SUCCESS, AGE = 20")
            SHOULD_INT_EQUAL(state, SUCCESS);
            SHOULD_INT_EQUAL(age, 20);
        THEN_END
        
    SCENARIO_END

    SCENARIO("reset age before initial")

        GIVEN("age = 20")
        GIVEN_END

        WHEN("we invoke person_set_age function")
            int state = person_set_age(someone, 20);
            int age = person_get_age(someone);
        WHEN_END

        THEN("get state = SUCCESS, age = 20")
            SHOULD_INT_EQUAL(state, SUCCESS);
            SHOULD_INT_EQUAL(age, 20);
        THEN_END
        
    SCENARIO_END

    SCENARIO("reset invalid age")

        GIVEN("age more than up bound, age = 61")
        GIVEN_END

        WHEN("we invoke person_set_age function")
            int state = person_set_age(someone, 61);
        WHEN_END

        THEN("get state = INVALID_ARGV")
            SHOULD_INT_EQUAL(state, INVALID_ARGV);
        THEN_END
        
    SCENARIO_END

    SCENARIO("reset invalid age")

        GIVEN("age more lower up bound, age = -1")
        GIVEN_END

        WHEN("we invoke person_set_age function")
            int state = person_set_age(someone, -1);
        WHEN_END

        THEN("get state = INVALID_ARGV")
            SHOULD_INT_EQUAL(state, INVALID_ARGV);
        THEN_END
        
    SCENARIO_END
    
    person_destroy(someone);
FEATURE_END

FEATURE(4, "Test person_set_from_reader function")
    Person someone = person_create();
    
    SCENARIO("person set from string like 'xxxx, 12'")

        GIVEN("string:'Bob, 12'")
            char *reader = "Bob, 12";
        GIVEN_END

        WHEN("we invoke person_set_from_reader function")
            int state = person_set_from_reader(someone, reader);
            char *name = "Bob";
            int age = 12;
        WHEN_END

        THEN("get state = SUCCESS, name = Bob, age = 12")
            SHOULD_INT_EQUAL(state, SUCCESS);
            SHOULD_STR_EQUAL(name, "Bob");
            SHOULD_INT_EQUAL(age, 12);
        THEN_END

    SCENARIO_END

    SCENARIO("person set from invalid string like 'xxxxxx'")

        GIVEN("invalid string 'xxxxxxxx'")
            char *reader = "Bob12";
        GIVEN_END

        WHEN("we invoke person_set_from_reader function")
            int state = person_set_from_reader(someone, reader);
        WHEN_END

        THEN("get state = INVALID_ARGV")
            SHOULD_INT_EQUAL(state, INVALID_ARGV);
        THEN_END

    SCENARIO_END

    SCENARIO("person set from invalid string like 'xxx, INVALID_AGE'")

        GIVEN("invalid string 'Bob, 61'")
            char *reader = "Bob, 61";
        GIVEN_END

        WHEN("we invoke person_set_from_reader function")
            int state = person_set_from_reader(someone, reader);
        WHEN_END

        THEN("get state = INVALID_ARGV")
            SHOULD_INT_EQUAL(state, INVALID_ARGV);
        THEN_END

    SCENARIO_END

    person_destroy(someone);
FEATURE_END

FEATURE(5, "Test person_equal function")
    Person p1 = person_create();
    Person p2 = person_create();

    SCENARIO("same name and same age")

        GIVEN("p1: Bob,12  p2: Bob 12")
            person_init(p1, "Bob", 12);
            person_init(p2, "Bob", 12);
        GIVEN_END

        WHEN("we invoke person_equal function")
            int state = person_equal(p1, p2);
        WHEN_END

        THEN("get state = TRUE")
            SHOULD_INT_EQUAL(state, TRUE);
        THEN_END

    SCENARIO_END

    SCENARIO("same name and different age")

        GIVEN("p1: Bob,13  p2: Bob 12")
            person_init(p1, "Bob", 13);
            person_init(p2, "Bob", 12);
        GIVEN_END

        WHEN("we invoke person_equal function")
            int state = person_equal(p1, p2);
        WHEN_END

        THEN("get state = FALSE")
            SHOULD_INT_EQUAL(state, FALSE);
        THEN_END

    SCENARIO_END

    SCENARIO("different name and same age")

        GIVEN("p1: Jack,12  p2: Bob 12")
            person_init(p1, "Jack", 12);
            person_init(p2, "Bob", 12);
        GIVEN_END

        WHEN("we invoke person_equal function")
            int state = person_equal(p1, p2);
        WHEN_END

        THEN("get state = FALSE")
            SHOULD_INT_EQUAL(state, FALSE);
        THEN_END

    SCENARIO_END

    SCENARIO("different name and different age")

        GIVEN("p1: Jack,13  p2: Bob 12")
            person_init(p1, "Jack", 13);
            person_init(p2, "Bob", 12);
        GIVEN_END

        WHEN("we invoke person_equal function")
            int state = person_equal(p1, p2);
        WHEN_END

        THEN("get state = FALSE")
            SHOULD_INT_EQUAL(state, FALSE);
        THEN_END

    SCENARIO_END

    person_destroy(p1);
    person_destroy(p2);
FEATURE_END

int main()
{
    cbehave_feature person_feature[] = {{feature_idx(1)}, {feature_idx(2)}, {feature_idx(3)}, {feature_idx(4)}, {feature_idx(5)}};
    return cbehave_runner("Person Features are as belows:", person_feature);
}
