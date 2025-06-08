// Copyright 2022 NNTU-CS
#ifndef TRAIN_H
#define TRAIN_H

class Train {
private:
    struct Car {
        bool light;
        Car* next;
        Car* prev;
    };

    Car* first;
    int countOp;

public:
    Train();
    void addCar(bool light);
    int getLength();
    int getOpCount();
};

#endif // TRAIN_H
