#pragma once

#include "Engine.hpp"
#include "Battery.hpp"
#include "Wheel.hpp"
#include "Brake.hpp"
#include "Transmission.hpp"
#include <vector>
#include <string>
#include <iostream>

class Car
{
public:
    Car(const std::string& brand, const std::string& model, std::unique_ptr<Engine> engine,
        std::unique_ptr<Transmission> transmission, std::vector<std::unique_ptr<Wheel>> wheels, 
        std::vector<std::unique_ptr<Brake>> brakes);

    virtual void printDetails() const;

    virtual ~Car() = default; // Use default destructor since smart pointers manage memory

protected:
    std::string brand_;
    std::string model_;
    std::unique_ptr<Engine> engine_;
    std::unique_ptr<Transmission> transmission_;
    std::vector<std::unique_ptr<Wheel>> wheels_;
    std::vector<std::unique_ptr<Brake>> brakes_;
};
