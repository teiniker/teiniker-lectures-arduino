#include <unity.h>
#include <stdbool.h>
#include <Arduino.h>
#include <base64.hpp>

/**
 * The following test cases check the number of bytes used 
 * to represent different data types on the ESP32-C6 board.
 */

void setUp(void) 
{
    // set stuff up here
}

void tearDown(void) 
{
    // clean stuff up here
}

void test_bytes_to_base64(void)
{
    // Setup
    unsigned char binary[] = {133, 244, 117, 206, 178, 195};
    unsigned char base64[9]; // 8 bytes for output + 1 for null terminator

    // Exercise
    unsigned int base64_length = encode_base64(binary, 6, base64);
    base64[base64_length] = '\0'; // Null-terminate the string

    // Vervify
    TEST_ASSERT_EQUAL(8, base64_length);
    TEST_ASSERT_EQUAL_STRING("hfR1zrLD", (const char*)base64);
}

void test_base64_to_bytes(void)
{
    // Setup
    unsigned char base64[] = "hfR1zrLD";
    unsigned char binary[6]; // 6 bytes for output

    // Exercise
    unsigned int binary_length = decode_base64(base64, binary);

    // Vervify 
    unsigned char expected_binary[] = {133, 244, 117, 206, 178, 195};
    TEST_ASSERT_EQUAL(6, binary_length);
    TEST_ASSERT_EQUAL_UINT8_ARRAY(expected_binary, binary, binary_length);
}

void setup() 
{
    delay(2000); // wait for the serial connection to be established

    UNITY_BEGIN();
    RUN_TEST(test_bytes_to_base64);
    RUN_TEST(test_base64_to_bytes);
    UNITY_END();
}

void loop() 
{
    // nothing to do here
}
