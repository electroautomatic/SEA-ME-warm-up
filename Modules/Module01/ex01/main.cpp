#include <QCoreApplication>
#include <QDebug>
#include <QString>

class Car {
protected:
    QString make;
    QString model;
    int year;

public:
    // Constructor
    Car(const QString& mk, const QString& mdl, int yr) : make(mk), model(mdl), year(yr) {
        qDebug() << "Car Constructor: Creating a car with make:" << make << ", model:" << model << ", year:" << year;
    }

    // Copy Constructor
    Car(const Car& other) : make(other.make), model(other.model), year(other.year) {
        qDebug() << "Car Copy Constructor: Copying a car with make:" << make << ", model:" << model << ", year:" << year;
    }

    // Copy Assignment Operator
    Car& operator=(const Car& other) {
        if (this != &other) {
            make = other.make;
            model = other.model;
            year = other.year;
            qDebug() << "Car Copy Assignment: Assigning a car with make:" << make << ", model:" << model << ", year:" << year;
        }
        return *this;
    }

    // Destructor
    virtual ~Car() {
        qDebug() << "Car Destructor: Destroying a car with make:" << make << ", model:" << model << ", year:" << year;
    }

    // Drive function
    virtual void drive() const {
        qDebug() << "Driving" << make << model << year << "edition.";
    }
};

class SportsCar : public Car {
private:
    int topSpeed;

public:
    // Constructor
    SportsCar(const QString& mk, const QString& mdl, int yr, int ts) : Car(mk, mdl, yr), topSpeed(ts) {
        qDebug() << "SportsCar Constructor: Creating a sports car with top speed:" << topSpeed;
    }

    // Copy Constructor
    SportsCar(const SportsCar& other) : Car(other), topSpeed(other.topSpeed) {
        qDebug() << "SportsCar Copy Constructor: Copying a sports car with top speed:" << topSpeed;
    }

    // Copy Assignment Operator
    SportsCar& operator=(const SportsCar& other) {
        if (this != &other) {
            Car::operator=(other);
            topSpeed = other.topSpeed;
            qDebug() << "SportsCar Copy Assignment: Assigning a sports car with top speed:" << topSpeed;
        }
        return *this;
    }

    // Destructor
    ~SportsCar() {
        qDebug() << "SportsCar Destructor: Destroying a sports car with top speed:" << topSpeed;
    }

    // Drive function
    void drive() const override {
        Car::drive();
        qDebug() << "Driving at top speed of" << topSpeed << "km/h.";
    }
};

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
