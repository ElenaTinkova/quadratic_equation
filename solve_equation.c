#include "quadratic_equation.h"

#include <math.h>
#include <stdio.h>

void non_standard_quadratic(double a, double b, double c, Root *roots) {
  if (b == 0 && c == 0) {
    roots->x1 = 0;
    roots->x2 = 0;
  } else if (b == 0 && c != 0) {
    if (-c / a > 0) {
      roots->x1 = sqrt(-c / a);
      roots->x2 = -1 * roots->x1;
    }
  } else if (c == 0 && b != 0) {
    roots->x1 = 0;
    roots->x2 = -b / a;
  }
}

Root solve_equation(double a, double b, double c) {
  Root roots = {NAN, NAN};
  if (a != 0) {  // при a = 0 уравнение линейное
    if (b != 0 || c != 0) {
      double discriminant = b * b - 4 * a * c;
      if (discriminant > 0) { // уравнение имеет два корня
        roots.x1 = (-b + sqrt(discriminant)) / (2 * a);
        roots.x2 = (-b - sqrt(discriminant)) / (2 * a);
      } else if (discriminant == 0) { // уравнение имеет один корень
        roots.x1 = -b / (2 * a);
        roots.x2 = roots.x1;
      }
    } else {
      non_standard_quadratic(a, b, c, &roots);
    }
  }
  return roots;
}
