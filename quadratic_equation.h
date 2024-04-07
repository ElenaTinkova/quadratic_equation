/*!
\file
\brief Функции для работы с модулем quadratic_equation
*/

#pragma once

/*!
 * Структура для записи и хранениия значений корней квадратного уравнениия
 * \param x1 значение первого корня (NAN, если корня не существует)
 * \param x2 значение второго корня (NAN, если корня не существует)
 */
typedef struct {
  double x1;
  double x2;
} Root;

/*!
Решает неполное квадратное уравнение
\param b, c Коэффициент уравнения
\param *roots Структура для значений корней
*/
void non_standard_quadratic(double a, double b, double c, Root *roots);

/*!
Решает квадратное уравнение
\param a,b,c Коэффициент уравнения
\return Возвращает структуру root со значениями корней уравнения,
если действительных корней не существует переменные корней хранят NAN
*/
Root solve_equation(double a, double b, double c);
