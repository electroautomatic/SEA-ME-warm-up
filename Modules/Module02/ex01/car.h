#ifndef CAR_H
#define CAR_H

#include "engine.h"
#include "wheel.h"
#include "brake.h"
#include "transmission.h"
#include <iostream>
#include <memory>
#include <vector>
#include <QString>

class Car {
public:
    Car(const QString& make, const QString& model)
        : make_(make), model_(model) {
        engine_ = std::make_unique<Engine>(1020, 1050); // Tesla Model S Plaid
        for (int i = 0; i < 4; ++i) {
            wheels_.emplace_back(std::make_unique<Wheel>(19)); // 19 inch wheels
            brakes_.emplace_back(std::make_unique<Brake>("Carbon Ceramic"));
        }
        transmission_ = std::make_unique<Transmission>("Single-Speed");
    }

    void printParts() {
        std::cout << "Car Make: " << make_.toStdString() << ", Model: " << model_.toStdString() << std::endl;
        engine_->print();
        for (const auto& wheel : wheels_) {
            wheel->print();
        }
        for (const auto& brake : brakes_) {
            brake->print();
        }
        transmission_->print();
    }

private:
    QString make_;
    QString model_;
    std::unique_ptr<Engine> engine_;
    std::vector<std::unique_ptr<Wheel>> wheels_;
    std::vector<std::unique_ptr<Brake>> brakes_;
    std::unique_ptr<Transmission> transmission_;
};

#endif // CAR_H
