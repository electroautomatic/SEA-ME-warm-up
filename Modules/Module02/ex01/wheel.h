#ifndef WHEEL_H
#define WHEEL_H

#include "part.h"
#include <iostream>

class Wheel : public Part {
public:
    Wheel(int diameter) : diameter_(diameter) {}
    void print() override {
        std::cout << "Wheel: " << diameter_ << " inch" << std::endl;
    }

private:
    int diameter_;
};

#endif // WHEEL_H
