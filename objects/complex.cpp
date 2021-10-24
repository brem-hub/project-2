#include "complex.h"

void complex::out(FILE* out) {
    fprintf(out, "complex number: (%lf, %lfi); double representation: %lf\n", _real, _imaginary, castToDouble());
}

void complex::random() {
    _real = randomDouble(-100, 100);
    _imaginary = randomDouble(-100, 100);
}

double complex::castToDouble() {
    return sqrt(_real * _real + _imaginary * _imaginary);
}

void complex::outConfig(FILE* out) {
    fprintf(out, "%d\n", number::COMPLEX);
    fprintf(out, "%lf %lf\n", _real, _imaginary);
}
int complex::in(FILE *input) {
    double real, imaginary;
    int res = fscanf(input, "%lf %lf", &real, &imaginary);
    if (res != 2) {
        printf("Could not read complex number\n");
        return 1;
    }
    _real = real;
    _imaginary = imaginary;

    return 0;
}
