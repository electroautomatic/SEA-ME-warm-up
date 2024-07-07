#include "sportscar.h"

SportsCar::SportsCar(const QString& mk, const QString& mdl, int yr, int ts) : Car(mk, mdl, yr), topSpeed(ts) {
    qDebug() << "SportsCar Constructor: Creating a sports car with top speed:" << topSpeed;
}

SportsCar::SportsCar(const SportsCar& other) : Car(other), topSpeed(other.topSpeed) {
    qDebug() << "SportsCar Copy Constructor: Copying a sports car with top speed:" << topSpeed;
}

SportsCar& SportsCar::operator=(const SportsCar& other) {
    if (this != &other) {
        Car::operator=(other);
        topSpeed = other.topSpeed;
        qDebug() << "SportsCar Copy Assignment: Assigning a sports car with top speed:" << topSpeed;
    }
    return *this;
}

SportsCar::~SportsCar() {
    qDebug() << "SportsCar Destructor: Destroying a sports car with top speed:" << topSpeed;
}

void SportsCar::drive() const {
    Car::drive();
    qDebug() << "Driving at top speed of" << topSpeed << "km/h.";
}
