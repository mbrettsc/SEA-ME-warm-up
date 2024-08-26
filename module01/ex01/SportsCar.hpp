#pragma once

#include "Car.hpp"

class SportsCar : public Car
{
private:
    std::string _topSpeed;
public:
    SportsCar();
    SportsCar(const SportsCar &other);
    SportsCar &operator=(const SportsCar &other);
    ~SportsCar();

    void setTopSpeed(std::string topSpeed);
    std::string getTopSpeed() const;
    void drive() const;
};
