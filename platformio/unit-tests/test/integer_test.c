#include <unity.h>

void setUp(void) 
{
    // set stuff up here
}

void tearDown(void) 
{
    // clean stuff up here
}

void test_int_size(void)
{
    uint8_t size = sizeof(int);

    TEST_ASSERT_EQUAL(2, size);
}

int main( int argc, char **argv) 
{
    UNITY_BEGIN();
    RUN_TEST(test_int_size);

    UNITY_END();
}