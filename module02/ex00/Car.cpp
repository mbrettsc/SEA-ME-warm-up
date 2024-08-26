#include "Car.hpp"

Car::Car() : _name("Car"), _speed("0") {}

Car::~Car() {}

Car::Car(const Car &other) : _name(other._name), _speed(other._speed) {}

Car &Car::operator=(const Car &other)
{
    if (this == &other)
        return *this;
    _name = other._name;
    _speed = other._speed;
    return *this;
}

void Car::setName(std::string name)
{
    _name = name;
}

void Car::setSpeed(std::string speed)
{
    _speed = speed;
}

std::string Car::getName() const
{
    return _name;
}

std::string Car::getSpeed() const
{
    return _speed;
}
