#include "ElectricCar.hpp"

int main()
{
    // Creating a standard car
    std::vector<std::unique_ptr<Wheel>> wheels;
    for (int i = 0; i < 4; ++i) {
        wheels.push_back(std::make_unique<Wheel>(17));
    }
    
    std::vector<std::unique_ptr<Brake>> brakes;
    for (int i = 0; i < 4; ++i) {
        brakes.push_back(std::make_unique<Brake>("Disc"));
    }
    
    Car myCar("Toyota", "Camry", std::make_unique<Engine>(200), std::make_unique<Transmission>("Automatic"),
             std::move(wheels), std::move(brakes));
    myCar.printDetails();

    // Creating an electric car
    wheels.clear();
    for (int i = 0; i < 4; ++i) {
        wheels.push_back(std::make_unique<Wheel>(19));
    }
    
    brakes.clear();
    for (int i = 0; i < 4; ++i) {
        brakes.push_back(std::make_unique<Brake>("Regenerative"));
    }
    
    ElectricCar myElectricCar("Tesla", "Model S Plaid", std::make_unique<Engine>(1020), std::make_unique<Battery>(100),
                              std::make_unique<Transmission>("Single-Speed"), std::move(wheels), std::move(brakes),
                              std::make_unique<InfotainmentSystem>("11.0"), std::make_unique<Autopilot>("Full Self-Driving"));
    myElectricCar.printDetails();

    return 0;
}
