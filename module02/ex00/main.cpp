#include "Car.hpp"
#include <memory>

int main()
{
    {
        std::unique_ptr<Car> car1(new Car());
        std::unique_ptr<Car> car2(new Car(*car1));
        std::unique_ptr<Car> car3(new Car());
        car3 = std::move(car2);

        car1->setName("Toyota");
        car1->setSpeed("180");
        car3->setName("Ferrari");
        car3->setSpeed("320");

        std::cout << "Car1: " << car1->getName() << " " << car1->getSpeed() << std::endl;
        std::cout << "Car3: " << car3->getName() << " " << car3->getSpeed() << std::endl;

        // all pointers are deleted automatically after the scope
    }
    // car1->setName("Toyota"); : error: ‘car1’ was not declared in this scope
    {
        Car* car = new Car();

        car->setName("Lamborghini");
        car->setSpeed("350");

        std::cout << "Car with new: " << car->getName() << " " << car->getSpeed() << std::endl;

        delete car;
    }
    return 0;
}
