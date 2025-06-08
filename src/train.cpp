// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    first = nullptr;
    countOp = 0;
}

void Train::addCar(bool light) {
    Car* newCar = new Car;
    newCar->light = light;

    if (!first) {
        first = newCar;
        newCar->next = newCar;
        newCar->prev = newCar;
    }
    else {
        Car* last = first->prev;
        newCar->next = first;
        newCar->prev = last;
        first->prev = newCar;
        last->next = newCar;
    }
}

int Train::getLength() {
    countOp = 0;
    Car* current = first;

    int k = 1;
    while (true) {
        Car* walker = current;

        for (int i = 0; i < k; ++i) {
            walker = walker->next;
            ++countOp;
        }

        if (!walker->light) {
            walker->light = true;

            for (int i = 0; i < k; ++i) {
                walker = walker->prev;
                ++countOp;
            }

            if (walker->light) {
                return k;
            }
        }

        ++k;
    }
}

int Train::getOpCount() {
    return countOp;
}
