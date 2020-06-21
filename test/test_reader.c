#include "cbehave/cbehave.h"
#include "../src/reader.h"
#include "../src/error.h"

FEATURE(1, "Test reader_set_from_file function")
    FILE *fp = fopen("test_data.txt", "r");
    char reader[READER_MAX];

    SCENARIO("reader first line")

        GIVEN("first line: BOb, 12")
        GIVEN_END

        WHEN("we invoke reader_set_from_file function")
            int state = reader_set_from_file(reader, fp);
        WHEN_END

        THEN("get state = SUCCESS, reader = BOb, 12")
            SHOULD_INT_EQUAL(state, SUCCESS);
            SHOULD_STR_EQUAL(reader, "Bob, 12\n");
        THEN_END

    SCENARIO_END

    SCENARIO("reader second line")

        GIVEN("second line: Andy, 11")
        GIVEN_END

        WHEN("we invoke reader_set_from_file function")
            int state = reader_set_from_file(reader, fp);
        WHEN_END

        THEN("get state = SUCCESS, reader = Andy, 11")
            SHOULD_INT_EQUAL(state, SUCCESS);
            SHOULD_STR_EQUAL(reader, "Andy, 11");
        THEN_END
        
    SCENARIO_END

    SCENARIO("reader third line")

        GIVEN("empty line: ")
        GIVEN_END

        WHEN("we invoke reader_set_from_file function")
            int state = reader_set_from_file(reader, fp);
        WHEN_END

        THEN("get state = READER_OVER")
            SHOULD_INT_EQUAL(state, READER_OVER);
        THEN_END
        
    SCENARIO_END

    fclose(fp);
FEATURE_END

int main()
{
    cbehave_feature person_feature[] = {{feature_idx(1)}};
    return cbehave_runner("Reader Features are as belows:", person_feature);
}