#include <math.h>

#include "quadratic_equation.h"

Root solve_equation(double a, double b, double c) {
  Root roots = {NAN, NAN};
  if (a != 0) {  // при a = 0 уравнение линейное
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {  // уравнение имеет два корня
      roots.x1 = (-b + sqrt(discriminant)) / (2 * a);
      roots.x2 = (-b - sqrt(discriminant)) / (2 * a);
    } else if (discriminant == 0) {  // уравнение имеет один корень
      roots.x1 = -b / (2 * a);
      roots.x2 = roots.x1;
    }
  }
  return roots;
}
