#include "ElectricCar.hpp"

ElectricCar::ElectricCar(const std::string& brand, const std::string& model, std::unique_ptr<Engine> engine,
                         std::unique_ptr<Battery> battery, std::unique_ptr<Transmission> transmission,
                         std::vector<std::unique_ptr<Wheel>> wheels, std::vector<std::unique_ptr<Brake>> brakes,
                         std::unique_ptr<InfotainmentSystem> infotainment, std::unique_ptr<Autopilot> autopilot)
    : Car(brand, model, std::move(engine), std::move(transmission), std::move(wheels), std::move(brakes)),
      battery_(std::move(battery)), infotainment_(std::move(infotainment)), autopilot_(std::move(autopilot)) {}

void ElectricCar::printDetails() const
{
    Car::printDetails();
    battery_->print();
    infotainment_->print();
    autopilot_->print();
}
