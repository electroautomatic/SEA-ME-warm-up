#ifndef CAR_H
#define CAR_H

#include <QString>
#include <QDebug>

class Car {
private:
    QString make;
    QString model;
    int year;

protected:
    void setMake(const QString& mk) { make = mk; }
    void setModel(const QString& mdl) { model = mdl; }
    void setYear(int yr) { year = yr; }

public:
    Car(const QString& mk, const QString& mdl, int yr);
    Car(const Car& other);
    Car& operator=(const Car& other);
    virtual ~Car();

    QString getMake() const { return make; }
    QString getModel() const { return model; }
    int getYear() const { return year; }

    virtual void drive() const;
};

#endif // CAR_H
