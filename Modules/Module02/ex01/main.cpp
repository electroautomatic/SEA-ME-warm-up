#include <QCoreApplication>
#include "car.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Car myCar("Tesla", "Model S Plaid");
    myCar.printParts();

    return 0;
}
