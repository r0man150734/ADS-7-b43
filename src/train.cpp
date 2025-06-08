// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : first(nullptr), countOp(0) {}

Train::~Train() {
    if (!first) return;
    Car* cur = first->next;
    while (cur != first) {
        Car* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    delete first;
}

void Train::addCar(bool light) {
    Car* newCar = new Car{ light, nullptr, nullptr };
    if (!first) {
        newCar->next = newCar;
        newCar->prev = newCar;
        first = newCar;
    }
    else {
        Car* last = first->prev;
        newCar->next = first;
        newCar->prev = last;
        last->next = newCar;
        first->prev = newCar;
    }
}

int Train::getLength() {
    countOp = 0;
    Car* current = first;

    int k = 1;
    while (true) {
        Car* walker = current;
        // шаг вперёд на k вагонов
        for (int i = 0; i < k; ++i) {
            walker = walker->next;
            ++countOp;
        }

        if (!walker->light) {
            walker->light = true;

            // шаг назад на k вагонов
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

void Train::reset() {
    countOp = 0;
}
