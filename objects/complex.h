#ifndef PROJECT_CPP_OBJECTS_COMPLEX_H_
#define PROJECT_CPP_OBJECTS_COMPLEX_H_

#include <cmath>
#include "number.h"
#include "../utils/utils.h"

/*
 * Класс комплексных чисел.
 */
class complex : public number {
 public:
  complex(double real, double imaginary) : _real(real), _imaginary(imaginary) {}
  complex() : complex(0,0) {}

  /*
   * Ввод числа из файла.
   * @param: input - дескриптор файла, открытого на чтение.
   * @returns: status_code.
   */
  int in(FILE* input) override;

  /*
   * Вывести комплексное число в файл в формате ввода.
   * @param: out - дескриптор файла, открытого на запись.
   */
  void outConfig(FILE* out) override;

  /*
   * Вывести комплексное число в human-readable виде в файл.
   * @param: out - дескриптор файла, открытого на запись.
   */
  void out(FILE* out) override;

  /*
   * Случайное заполнение комплексного числа.
   */
  void random() override;

  /*
   * Double представление комплексного числа.
   * @returns: double представление комплексного числа.
   */
  double castToDouble() override;

 private:
  double _real; // вещественная часть комплексного числа.
  double _imaginary; // мнимая часть комплексного числа.
};

#endif //PROJECT_CPP_OBJECTS_COMPLEX_H_
