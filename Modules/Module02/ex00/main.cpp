#include <QCoreApplication>
#include "car.h"
#include "sportscar.h"
#include <memory>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Using unique_ptr
    std::unique_ptr<Car> car1 = std::make_unique<Car>("Toyota", "Corolla", 2020);
    car1->drive();

    // Using shared_ptr
    std::shared_ptr<SportsCar> sportsCar1 = std::make_shared<SportsCar>("Ferrari", "F8", 2021, 340);
    sportsCar1->drive();

    // Demonstrating shared_ptr with multiple owners
    std::shared_ptr<SportsCar> sportsCar2 = sportsCar1; // Shared ownership
    sportsCar2->drive();

    // Dynamically allocated Car object managed by unique_ptr
    std::unique_ptr<Car> car2 = std::make_unique<Car>("Honda", "Civic", 2019);
    car2->drive();

    return 0;
}
