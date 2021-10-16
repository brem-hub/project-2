#ifndef PROJECT_CPP_OBJECTS_POINT_H_
#define PROJECT_CPP_OBJECTS_POINT_H_

struct point{
  int x;
  int y;

  point(int x, int y): x(x), y(y) {}
  point(): point(0, 0) {}
};


#endif //PROJECT_CPP_OBJECTS_POINT_H_
