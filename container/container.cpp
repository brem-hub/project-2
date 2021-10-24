#include "complex.h"
#include "container.h"

container::container() {
    _size = 0;
    _array = new number*[MAX_CONTAINER_SIZE];
    for (int i = 0; i < MAX_CONTAINER_SIZE; ++i) {
        _array[i] = nullptr;
    }
}

container::~container() {
    for (int i = 0; i < _size; ++i) {
        delete _array[i];
    }
    _size = 0;
    delete _array;
}

int container::add(number *num) {
    if (_size > MAX_CONTAINER_SIZE) {
        printf("Container is filled, cannot add any new values\n");
        return 1;
    }
    _array[_size++] = num;
    return 0;
}

int container::fill(FILE* in) {
    int number_of_elements;
    int res = fscanf(in, "%d\n", &number_of_elements);

    if (res != 1) {
        printf("Could not parse number of elements\n");
        return 1;
    }

    if (number_of_elements > MAX_CONTAINER_SIZE) {
        printf("Number of elements > max_container_size: %d\n", MAX_CONTAINER_SIZE);
        return 1;
    }

    if (number_of_elements <= 0) {
        printf("Number of elements cannot be <= 0\n");
        return 1;
    }

    for (int i = 0; i < number_of_elements; ++i) {
        number* num = number::readNumber(in);
        if (num) {
            add(num);
        } else {
            return 1;
        }
    }
    return 0;
}

int container::randomFill(int counter, FILE* out) {
    if (counter > MAX_CONTAINER_SIZE) {
        printf("Number of elements > max_container_size: %d\n", MAX_CONTAINER_SIZE);
        return 1;
    }

    if (out) {
        fprintf(out, "%d\n", counter);
    }

    for (int i = 0; i < counter; ++i) {
        number* num;

        int type = randomInt(0, 3);

        switch (type) {
            case number::COMPLEX:
                num = new complex();
                break;
            case number::FRACTION:
                num = new fraction();
                break;
            case number::POLAR:
                num = new polar();
                break;
            default:
                printf("Could not generate correct number type\n");
                return 1;
        }
        num->random();
        if (out) {
            num->outConfig(out);
        }
        add(num);
    }
    return 0;
}

void container::straightSort() {
    for (int i = 0; i < _size; ++i) {
        number* num = _array[i];
        int j = i;
        while(j > 0 && _array[j-1]->castToDouble() > num->castToDouble()) {
            _array[j] = _array[j-1];
            j--;
        }
        _array[j] = num;
    }
}

void container::out(FILE* out) {
    for (int i = 0; i < _size; ++i) {
        fprintf(out, "%d: ", i);
        _array[i]->out(out);
    }
}