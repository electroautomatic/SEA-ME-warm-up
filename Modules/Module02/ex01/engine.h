#ifndef ENGINE_H
#define ENGINE_H

#include "part.h"
#include <iostream>

class Engine : public Part {
public:
    Engine(int horsepower, int torque) : horsepower_(horsepower), torque_(torque) {}
    void print() override {
        std::cout << "Engine: " << horsepower_ << " HP, " << torque_ << " Nm torque" << std::endl;
    }

private:
    int horsepower_;
    int torque_;
};

#endif // ENGINE_H
