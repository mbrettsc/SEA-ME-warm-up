#pragma once

#include "ACar.hpp"

class SportsCar : public ACar {
public:
    SportsCar(const std::string &brand, const std::string &model, const std::string& year, double topSpeed);
    ~SportsCar() = default;

    double getTopSpeed() const;
    void setTopSpeed(double topSpeed);

    void displayInfo() const override;

    SportsCar &operator=(const SportsCar &other);

private:
    double _topSpeed;
};