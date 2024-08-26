#pragma once

#include "Part.hpp"

class Wheel : public Part
{
public:
    Wheel(int diameter) : diameter_(diameter) {}

    void print() const override {
        std::cout << "Wheel: " << diameter_ << " inches\n";
    }

private:
    int diameter_;
};