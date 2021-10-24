#include "fraction.h"

void fraction::out(FILE* out) {
    fprintf(out, "fraction: %d/%d; double representation: %lf\n", _numerator, _denominator, castToDouble());
}
void fraction::random() {
    _numerator = randomInt(-100, 100);
    do {
        _denominator = randomInt(-100, 100);
    } while (_denominator == 0);
}
double fraction::castToDouble() {
    return (_numerator + 0.0) / _denominator;
}

void fraction::outConfig(FILE* out) {
    fprintf(out, "%d\n", number::FRACTION);
    fprintf(out, "%d %d\n", _numerator, _denominator);
}

int fraction::in(FILE *input) {
    int numerator, denominator;
    int res = fscanf(input, "%d %d", &numerator, &denominator);
    if (res != 2) {
        printf("Could not read fraction number\n");
        return 1;
    }
    _numerator = numerator;
    _denominator = denominator;

    return 0;
}
