#include <unity.h>
#include <stdbool.h>

/**
 * The following test cases check the number of bytes used 
 * to represent different data types on the Arduino Uno board.
 */

void setUp(void) 
{
    // set stuff up here
}

void tearDown(void) 
{
    // clean stuff up here
}

void test_size_bool(void)
{
    uint8_t size = sizeof(bool);
    TEST_ASSERT_EQUAL(1, size);
}

void test_size_short(void)
{
    uint8_t size = sizeof(short);
    TEST_ASSERT_EQUAL(2, size);
}

void test_size_int(void)
{
    uint8_t size = sizeof(int);
    TEST_ASSERT_EQUAL(4, size);
}

void test_size_long(void)
{
    uint8_t size = sizeof(long);
    TEST_ASSERT_EQUAL(4, size);
}

void test_size_longlong(void)
{
    uint8_t size = sizeof(long);
    TEST_ASSERT_EQUAL(4, size);
}

int main( int argc, char **argv) 
{
    UNITY_BEGIN();
    RUN_TEST(test_size_bool);
    RUN_TEST(test_size_short);
    RUN_TEST(test_size_int);
    RUN_TEST(test_size_long);
    RUN_TEST(test_size_longlong);

    UNITY_END();
}