#include <QCoreApplication>
#include <QDebug>
#include <QString>

class Car {
private:
    QString name;
    int speed;

public:
    // Default constructor
    Car(const QString& n = "", int s = 0) : name(n), speed(s) {}

    // Copy constructor
    Car(const Car& other) : name(other.name), speed(other.speed) {}

    // Copy assignment operator
    Car& operator=(const Car& other) {
        if (this == &other) {
            return *this;
        }

        name = other.name;
        speed = other.speed;

        return *this;
    }

    // Destructor
    ~Car() {}

    // Function to display car information
    void display() const {
        qDebug() << "Car Name:" << name << ", Speed:" << speed;
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    Car car1("Toyota", 120);
    Car car2 = car1;  // Invokes copy constructor
    Car car3;
    car3 = car1;      // Invokes copy assignment operator

    qDebug() << "Car1 details:";
    car1.display();

    qDebug() << "Car2 details:";
    car2.display();

    qDebug() << "Car3 details:";
    car3.display();

    return 0;
}
