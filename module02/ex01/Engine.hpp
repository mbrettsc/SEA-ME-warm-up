#pragma once

#include "Part.hpp"

class Engine : public Part
{
public:
    Engine(int horsepower) : horsepower_(horsepower) {}

    void print() const override {
        std::cout << "Electric Engine: " << horsepower_ << " HP\n";
    }

private:
    int horsepower_;
};
