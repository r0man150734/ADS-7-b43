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
    current->light = false;

    int step = 1;
    while (true) {
        Car* walker = current;
        for (int i = 0; i < step; ++i) {
            walker = walker->next;
            ++countOp;
        }

        if (!walker->light) {
            walker->light = true;

            for (int i = 0; i < step; ++i) {
                walker = walker->prev;
                ++countOp;
            }

            if (walker->light) {
                return step;
            }
        }

        ++step;
    }
}

int Train::getOpCount() {
    return countOp;
}

void Train::reset() {
    countOp = 0;
}
