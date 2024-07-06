#ifndef SPORTSCAR_H
#define SPORTSCAR_H

#include "car.h"

class SportsCar : public Car {
private:
    int topSpeed;

public:
    SportsCar(const QString& mk, const QString& mdl, int yr, int ts);
    SportsCar(const SportsCar& other);
    SportsCar& operator=(const SportsCar& other);
    ~SportsCar();

    int getTopSpeed() const { return topSpeed; }
    void setTopSpeed(int ts) { topSpeed = ts; }

    void drive() const override;
};

#endif // SPORTSCAR_H
