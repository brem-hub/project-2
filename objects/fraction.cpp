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
