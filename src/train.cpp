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

    Car* c0 = first;
    c0->light = true;

    Car* current = c0;
    int k = 1;

    while (true) {
        current = current->next;
        countOp += 2;

        if (current->light) {
            current->light = false;

            if (!c0->light) {
                return k;
            }
        }
        else {
            current->light = true;
        }

        ++k;
    }
}




int Train::getOpCount() {
    return countOp;
}
