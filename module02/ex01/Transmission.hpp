#pragma once

#include "Part.hpp"

class Transmission : public Part
{
public:
    Transmission(const std::string& type) : type_(type) {}

    void print() const override {
        std::cout << "Transmission: " << type_ << "\n";
    }

private:
    std::string type_;
};
