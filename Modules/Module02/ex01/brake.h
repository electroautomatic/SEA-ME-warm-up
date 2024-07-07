#ifndef BRAKE_H
#define BRAKE_H

#include "part.h"
#include <iostream>

class Brake : public Part {
public:
    Brake(const std::string& type) : type_(type) {}
    void print() override {
        std::cout << "Brake: " << type_ << std::endl;
    }

private:
    std::string type_;
};

#endif // BRAKE_H
