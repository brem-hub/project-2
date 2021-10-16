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

     switch (type) {
         case COMPLEX:{
             double real, imaginary;
             res = fscanf(in, "%lf %lf", &real, &imaginary);
             if (res != 2) {
                 printf("Could not read complex number\n");
                 return NULL;
             }
             return new complex(real, imaginary);
         }
         case FRACTION:{
             int numerator, denominator;
             res = fscanf(in, "%d %d", &numerator, &denominator);
             if (res != 2) {
                 printf("Could not read fraction number\n");
                 return NULL;
             }
             return new fraction(numerator, denominator);
         }
         case POLAR:{
             double angle;
             point coords;
             res = fscanf(in, "%lf %d %d", &angle, &coords.x, &coords.y);
             if (res != 3) {
                 printf("Could not read polar number\n");
                 return NULL;
             }
             return new polar(angle, coords);
         }
         default:
             printf("Could not read number\n");
             return NULL;
     }
}