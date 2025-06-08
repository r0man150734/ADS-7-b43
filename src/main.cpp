// Copyright 2022 NNTU-CS
#include <vector>
#include <chrono>
#include <random>
#include <iostream>
#include <iomanip>
#include "train.h"

void fillTrain(Train& t, int n, const std::string& mode) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1);

    for (int i = 0; i < n; ++i) {
        if (mode == "on")
            t.addCar(true);
        else if (mode == "off")
            t.addCar(false);
        else
            t.addCar(dis(gen));
    }
}

void experiment(const std::string& mode) {
    std::cout << "==== Mode: " << mode << " ====\n";
    std::cout << std::setw(8) << "N"
        << std::setw(15) << "Time (us)"
        << std::setw(15) << "OpCount" << "\n";

    for (int n = 2; n <= 100; n += 2) {
        Train t;
        fillTrain(t, n, mode);

        auto start = std::chrono::high_resolution_clock::now();
        int length = t.getLength();
        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        int ops = t.getOpCount();

        std::cout << std::setw(8) << n
            << std::setw(15) << duration
            << std::setw(15) << ops
            << "    # Length=" << length << "\n";
    }

    std::cout << "\n";
}

int main() {
    experiment("off");
    experiment("on");
    experiment("rand");

    return 0;
}
