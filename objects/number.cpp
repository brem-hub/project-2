#include "number.h"
#include "complex.h"
#include "polar.h"
#include "fraction.h"

 number* number::readNumber(FILE* in) {
     int type;

     int res = fscanf(in, "%d\n", &type);

     if (res != 1) {
         printf("Could not parse type of the number\n");
         return NULL;
     }

     number* num;

     switch (type) {
         case COMPLEX:
             num = new complex();
             break;
         case FRACTION:
             num = new fraction();
             break;
         case POLAR:
             num = new polar();
             break;
         default:
             printf("Could not read number\n");
             return NULL;
     }

     if (num->in(in)){
         printf("Error occurred while reading number, exiting\n");
         return NULL;
     }
     return num;
}