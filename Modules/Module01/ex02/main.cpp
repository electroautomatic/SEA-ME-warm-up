#include <QCoreApplication>
#include "car.h"
#include "sportscar.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Car car1("Toyota", "Corolla", 2020);
    car1.drive();

    SportsCar sportsCar1("Ferrari", "F8", 2021, 340);
    sportsCar1.drive();

    SportsCar sportsCar2 = sportsCar1; // Invokes copy constructor
    sportsCar2.drive();

    SportsCar sportsCar3("Porsche", "911", 2022, 330);
    sportsCar3 = sportsCar1; // Invokes copy assignment operator
    sportsCar3.drive();

    return 0;
}
