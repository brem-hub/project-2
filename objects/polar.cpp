#include "polar.h"

void polar::out(FILE* out) {
    fprintf(out, "polar: w=%lf; coords=(%d, %d); double representation: %lf\n", _angle,
            _coords.x, _coords.y, castToDouble());
}

void polar::random() {
    _angle = randomDouble(0, 10);
    _coords = point(randomInt(-100, 100), randomInt(-100, 100));
}

double polar::castToDouble() {
    return sqrt(_coords.x * _coords.x + _coords.y * _coords.y);
}

void polar::outConfig(FILE* out) {
    fprintf(out, "%d\n", number::POLAR);
    fprintf(out, "%lf %d %d\n", _angle, _coords.x, _coords.y);
}