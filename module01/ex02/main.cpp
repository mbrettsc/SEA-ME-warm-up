#include "SportsCar.hpp"

int main()
{
    // ACar car1("Toyota", "Corolla", "2019"); error: ACAR is an abstract class

    SportsCar sc1("Ferrari", "488", "2020", 330.0);
    SportsCar sc2("Lamborghini", "Huracan", "2021", 325.5);

    sc1.displayInfo();
    sc2.displayInfo();

    sc2 = sc1;
    sc2.displayInfo();

    ACar *carPtr = &sc1;
    carPtr->displayInfo();

    return 0;
}
