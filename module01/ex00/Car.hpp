#pragma once

#include <iostream>

class Car
{
private:
    std::string _name;
    std::string _speed;
public:
    Car();
    Car(const Car &other);
    Car &operator=(const Car &other);
    ~Car();

    void setName(std::string name);
    void setSpeed(std::string speed);

    std::string getName() const;
    std::string getSpeed() const;
};
