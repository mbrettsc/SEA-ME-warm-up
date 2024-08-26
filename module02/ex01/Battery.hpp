#pragma once

#include "Part.hpp"

class Battery : public Part
{
public:
    Battery(int capacity) : capacity_(capacity) {}

    void print() const override {
        std::cout << "Battery: " << capacity_ << " kWh\n";
    }

private:
    int capacity_;
};
