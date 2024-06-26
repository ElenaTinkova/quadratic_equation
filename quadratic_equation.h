/*!
\file
\brief Функция для работы с модулем quadratic_equation
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
Решает квадратное уравнение
\param a, b, c Коэффициент уравнения
\return Возвращает структуру Root со значениями корней уравнения,
если действительных корней не существует переменные корней хранят NAN
*/
Root solve_equation(double a, double b, double c);
