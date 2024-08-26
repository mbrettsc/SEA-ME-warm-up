#pragma once

#include <iostream>

class Car
{
protected:
    std::string _make;
    std::string _model;
    std::string _year;
public:
    Car();
    Car(const Car &other);
    Car &operator=(const Car &other);
    ~Car();

    void setMake(std::string make);
    void setModel(std::string model);
    void setYear(std::string year);

    std::string getMake() const;
    std::string getModel() const;
    std::string getYear() const;

    void drive() const;
};
