#include <check.h>
#include "lib.h"

START_TEST(test_calculate_digit_frequency) {
    char text[] = "В 1991 году Украина получила независимость, тогда моему папе было 18 лет!";
    int freq[10] = {0};
    calculate_digit_frequency(text, freq);
    ck_assert_int_eq(freq[0], 2);
    ck_assert_int_eq(freq[1], 2);
    ck_assert_int_eq(freq[8], 1);
}

Suite *digit_frequency_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Digit Frequency");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_calculate_digit_frequency);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = digit_frequency_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
