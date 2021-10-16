#ifndef PROJECT_CPP_OBJECTS_POLAR_H_
#define PROJECT_CPP_OBJECTS_POLAR_H_

#include "number.h"
#include "point.h"
#include "../utils/utils.h"

/*
 * Класс полярных чисел.
 */
class polar : public number {
 public:
  polar(double angle, point coords): _angle(angle), _coords(coords) {}
  polar(): polar(0.0, point(0, 0)) {}

  /*
   * Вывести полярное число в файл в формате ввода.
   * @param: out - дескриптор файла, открытый на запись.
   */
  void outConfig(FILE*) override;

  /*
   * Вывести полярное число в human-readable виде в файл.
   * @param: out - дескриптор файла, открытый на запись.
   */
  void out(FILE*) override;

  /*
   * Случайное заполнение полярного числа.
   */
  void random() override;

  /*
   * Double представление полярного числа.
   * @returns: double представление полярного числа.
   */
  double castToDouble() override;

 private:
  double _angle;  // полярный угол.
  point _coords;  // полярная точка.

};

#endif //PROJECT_CPP_OBJECTS_POLAR_H_
