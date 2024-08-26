#include "SportsCar.hpp"

int main()
{
    Car car;
    car.setMake("Ferrari");
    car.setModel("F8 Tributo");
    car.setYear("2020");

    car.drive();

    SportsCar sportsCar;
    sportsCar.setMake("Ferrari");
    sportsCar.setModel("F8 Tributo");
    sportsCar.setYear("2020");
    sportsCar.setTopSpeed("340 km/h");

    sportsCar.drive();

    return 0;
}
