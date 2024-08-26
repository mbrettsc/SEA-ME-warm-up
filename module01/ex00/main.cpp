#include "Car.hpp"

int main()
{
    Car car;
    car.setName("Ferrari");
    car.setSpeed("200");
    std::cout << "Car name: " << car.getName() << std::endl;
    std::cout << "Car speed: " << car.getSpeed() << std::endl;

    Car car2(car);
    std::cout << "Car2 name: " << car2.getName() << std::endl;
    std::cout << "Car2 speed: " << car2.getSpeed() << std::endl;
    
    Car car3;
    car3 = car;
    std::cout << "Car3 name: " << car3.getName() << std::endl;
    std::cout << "Car3 speed: " << car3.getSpeed() << std::endl;
    return 0;
}
