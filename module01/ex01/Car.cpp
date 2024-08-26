#include "Car.hpp"

Car::Car() : _make("Car"), _model("Model"), _year("Year") {}

Car::~Car() {}

Car::Car(const Car &other) : _make(other._make), _model(other._model), _year(other._year) {}

Car &Car::operator=(const Car &other)
{
    if (this == &other)
        return *this;
    _make = other._make;
    _model = other._model;
    _year = other._year;
    return *this;
}

void Car::setMake(std::string make)
{
    _make = make;
}

void Car::setModel(std::string model)
{
    _model = model;
}

void Car::setYear(std::string year)
{
    _year = year;
}

std::string Car::getMake() const
{
    return _make;
}

std::string Car::getModel() const
{
    return _model;
}

std::string Car::getYear() const
{
    return _year;
}

void Car::drive() const
{
    std::cout << "Driving a " << _make << " " << _model << " " << _year << std::endl;
}
