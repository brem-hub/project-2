#ifndef PROJECT_CPP_OBJECTS_FRACTION_H_
#define PROJECT_CPP_OBJECTS_FRACTION_H_

#include "number.h"
#include "../utils/utils.h"

/*
 * Класс дробных чисел.
 */
class fraction: public number {
 public:
  fraction(int num, int denom): _numerator(num), _denominator(denom) {}
  fraction(): fraction(0,0) {}

  /*
   * Ввести число из файла.
   * @param: input - дескриптор файла, открытый на чтение.
   * @returns: status_code.
   */
  int in(FILE* input) override;

  /*
   * Вывести дробное число в файл в формате ввода.
   * @param: out - дескриптор файла, открытый на запись.
   */
  void outConfig(FILE* out) override;

  /*
   * Вывести дробное число в human-readable виде в файл.
   * @param: out - дескриптор файла, открытый на запись.
   */
  void out(FILE*) override;

  /*
   * Случайное заполнение дробного числа.
   */
  void random() override;

  /*
   * Double представление дробного числа.
   * @returns: double представление дробного числа.
   */
  double castToDouble() override;

 private:
  int _numerator;  // числитель дроби.
  int _denominator; // знаменатель дроби.
};

#endif //PROJECT_CPP_OBJECTS_FRACTION_H_
