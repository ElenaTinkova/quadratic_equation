#include "solve_equation_test.h"

#include "../quadratic_equation.h"

START_TEST(two_real_roots) {
  Root result = solve_equation(1, -3, 2);
  ck_assert_double_eq_tol(result.x1, 2, 1e-6);
  ck_assert_double_eq_tol(result.x2, 1, 1e-6);
}
END_TEST

START_TEST(double_root) {
  Root result = solve_equation(1, -2, 1);
  ck_assert_double_eq_tol(result.x1, 1, 1e-6);
  ck_assert_double_eq_tol(result.x2, 1, 1e-6);
}
END_TEST

START_TEST(no_roots) {
  Root result = solve_equation(1, 2, 5);
  ck_assert_double_nan(result.x1);
  ck_assert_double_nan(result.x2);
}
END_TEST

START_TEST(non_standard_b_and_c_zero) {
  Root result = solve_equation(2, 0, 0);
  ck_assert_double_eq_tol(result.x1, 0, 1e-6);
  ck_assert_double_eq_tol(result.x2, 0, 1e-6);
}
END_TEST

START_TEST(non_standard_b_zero_c_positive) {
  Root result = solve_equation(-1, 0, 1);
  ck_assert_double_eq_tol(result.x1, -1, 1e-6);
  ck_assert_double_eq_tol(result.x2, 1, 1e-6);
}
END_TEST

START_TEST(non_standard_b_zero_c_negative) {
  Root result = solve_equation(1, 0, 1);
  ck_assert_double_nan(result.x1);
  ck_assert_double_nan(result.x2);
}
END_TEST

START_TEST(non_standard_c_zero) {
  Root result = solve_equation(1, 1, 0);
  ck_assert_double_eq_tol(result.x1, 0, 1e-6);
  ck_assert_double_eq_tol(result.x2, -1, 1e-6);
}
END_TEST

START_TEST(linear_equation) {
  Root result = solve_equation(0, 2, 5);
  ck_assert_double_nan(result.x1);
  ck_assert_double_nan(result.x2);
}
END_TEST

START_TEST(sum_options_zero) {
  Root result = solve_equation(13, 12, -25);
  ck_assert_double_eq_tol(result.x1, 1, 1e-6);
  ck_assert_double_eq_tol(result.x2, -1.923076, 1e-6);
}
END_TEST

void srunner_quadratic_equation(SRunner *sr) {
  Suite *suit_1 = suite_create("quadratic equations");
  TCase *tc1_1 = tcase_create("core");

  suite_add_tcase(suit_1, tc1_1);
  srunner_add_suite(sr, suit_1);

  tcase_add_test(tc1_1, two_real_roots);
  tcase_add_test(tc1_1, double_root);
  tcase_add_test(tc1_1, no_roots);
  tcase_add_test(tc1_1, non_standard_b_and_c_zero);
  tcase_add_test(tc1_1, non_standard_b_zero_c_positive);
  tcase_add_test(tc1_1, non_standard_b_zero_c_negative);
  tcase_add_test(tc1_1, non_standard_c_zero);
  tcase_add_test(tc1_1, linear_equation);
  tcase_add_test(tc1_1, sum_options_zero);
}

int main() {
  Suite *s = suite_create("quadratic equation tests");
  SRunner *sr = srunner_create(s);
  int err;

  srunner_quadratic_equation(sr);

  srunner_run_all(sr, CK_NORMAL);
  err = srunner_ntests_failed(sr);
  srunner_free(sr);

  return err == 0 ? 0 : 1;
}
