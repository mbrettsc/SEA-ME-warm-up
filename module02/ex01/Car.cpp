#include "Car.hpp"

Car::Car(const std::string& brand, const std::string& model, std::unique_ptr<Engine> engine,
         std::unique_ptr<Transmission> transmission, std::vector<std::unique_ptr<Wheel>> wheels, 
         std::vector<std::unique_ptr<Brake>> brakes)
    : brand_(brand), model_(model), engine_(std::move(engine)), transmission_(std::move(transmission)),
      wheels_(std::move(wheels)), brakes_(std::move(brakes)) {}

void Car::printDetails() const
{
    std::cout << "Car: " << brand_ << " " << model_ << "\n";
    engine_->print();
    transmission_->print();
    for (const auto& wheel : wheels_) {
        wheel->print();
    }
    for (const auto& brake : brakes_) {
        brake->print();
    }
}
