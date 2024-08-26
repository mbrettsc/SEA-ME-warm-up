#include "SportsCar.hpp"

SportsCar::SportsCar() : _topSpeed("Top Speed") {}

SportsCar::~SportsCar() {}

SportsCar::SportsCar(const SportsCar &other) : Car(other), _topSpeed(other._topSpeed) {}

SportsCar &SportsCar::operator=(const SportsCar &other)
{
    if (this == &other)
        return *this;
    Car::operator=(other);
    _topSpeed = other._topSpeed;
    return *this;
}

void SportsCar::setTopSpeed(std::string topSpeed)
{
    _topSpeed = topSpeed;
}

std::string SportsCar::getTopSpeed() const
{
    return _topSpeed;
}

void SportsCar::drive() const
{
    std::cout << "Driving a " << getMake() << " " << getModel() << " " << getYear() << " with top speed " << _topSpeed << std::endl;
}
