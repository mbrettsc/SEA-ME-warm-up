#include "SportsCar.hpp"

SportsCar::SportsCar(const std::string &make, const std::string &model, const std::string& year, double topSpeed)
    : ACar(make, model, year), _topSpeed(topSpeed) {}

double SportsCar::getTopSpeed() const {
    return _topSpeed;
}

void SportsCar::setTopSpeed(double topSpeed) {
    _topSpeed = topSpeed;
}

void SportsCar::displayInfo() const {
    std::cout << "Brand: " << _make << ", Model: " << _model << ", Year: " << _year << ", Top Speed: " << _topSpeed << " km/h" << std::endl;
}

SportsCar &SportsCar::operator=(const SportsCar &other) {
    if (this == &other)
        return *this;
    ACar::operator=(other);
    _topSpeed = other._topSpeed;
    return *this;
}
