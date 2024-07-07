#ifndef TRANSMISSION_H
#define TRANSMISSION_H

#include "part.h"
#include <iostream>

class Transmission : public Part {
public:
    Transmission(const std::string& type) : type_(type) {}
    void print() override {
        std::cout << "Transmission: " << type_ << std::endl;
    }

private:
    std::string type_;
};

#endif // TRANSMISSION_H
