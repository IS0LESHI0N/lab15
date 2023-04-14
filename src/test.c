#include <stdlib.h>
#include <check.h>
#include "lib.h"

START_TEST(test_read_classrooms)
{
    int num_classrooms;
    Classroom *classrooms = read_classrooms("test_input.txt", &num_classrooms);

    ck_assert_int_eq(num_classrooms, 2);
    ck_assert_str_eq(classrooms[0].name, "25a");
    ck_assert_int_eq(classrooms[0].capacity, 50);
    ck_assert_str_eq(classrooms[0].location, "Корпус 1: поверх 2");
    ck_assert_str_eq(classrooms[0].condition, "потребує ремонту");
    ck_assert_int_eq(classrooms[0].is_occupied, 0);

    ck_assert_str_eq(classrooms[1].name, "313");
    ck_assert_int_eq(classrooms[1].capacity, 180);
    ck_assert_str_eq(classrooms[1].location, "Корпус 2: поверх 1");
    ck_assert_str_eq(classrooms[1].condition, "не потребує ремонту");
    ck_assert_int_eq(classrooms[1].is_occupied, 1);

free(classrooms[0].name);
free(classrooms[0].location);
free(classrooms[0].condition);
free(classrooms[1].name);
free(classrooms[1].location);
free(classrooms[1].condition);

}
END_TEST

Suite *lib_suite(void) {
Suite *s;
TCase *tc_core;
s = suite_create("Lib");
tc_core = tcase_create("Core");
tcase_add_test(tc_core, test_read_classrooms);
suite_add_tcase(s, tc_core);

return s;
}

int main(void) {
int number_failed;
Suite *s;
SRunner *sr;
s = lib_suite();
sr = srunner_create(s);

srunner_run_all(sr, CK_NORMAL);
number_failed = srunner_ntests_failed(sr);
srunner_free(sr);

return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
