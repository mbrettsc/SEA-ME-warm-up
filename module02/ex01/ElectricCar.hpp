#pragma once

#include "Car.hpp"
#include "Battery.hpp"
#include "InfotainmentSystem.hpp"
#include "Autopilot.hpp"

class ElectricCar : public Car
{
public:
    ElectricCar(const std::string& brand, const std::string& model, std::unique_ptr<Engine> engine,
                std::unique_ptr<Battery> battery, std::unique_ptr<Transmission> transmission,
                std::vector<std::unique_ptr<Wheel>> wheels, std::vector<std::unique_ptr<Brake>> brakes,
                std::unique_ptr<InfotainmentSystem> infotainment, std::unique_ptr<Autopilot> autopilot);

    void printDetails() const override;

private:
    std::unique_ptr<Battery> battery_;
    std::unique_ptr<InfotainmentSystem> infotainment_;
    std::unique_ptr<Autopilot> autopilot_;
};
