#include "car.h"

Car::Car(const QString& mk, const QString& mdl, int yr) : make(mk), model(mdl), year(yr) {
    qDebug() << "Car Constructor: Creating a car with make:" << make << ", model:" << model << ", year:" << year;
}

Car::Car(const Car& other) : make(other.make), model(other.model), year(other.year) {
    qDebug() << "Car Copy Constructor: Copying a car with make:" << make << ", model:" << model << ", year:" << year;
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        make = other.make;
        model = other.model;
        year = other.year;
        qDebug() << "Car Copy Assignment: Assigning a car with make:" << make << ", model:" << model << ", year:" << year;
    }
    return *this;
}

Car::~Car() {
    qDebug() << "Car Destructor: Destroying a car with make:" << make << ", model:" << model << ", year:" << year;
}

void Car::drive() const {
    qDebug() << "Driving" << make << model << year << "edition.";
}
