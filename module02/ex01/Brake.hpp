#pragma once

#include "Part.hpp"

class Brake : public Part
{
public:
    Brake(const std::string& type) : type_(type) {}

    void print() const override {
        std::cout << "Brake: " << type_ << "\n";
    }

private:
    std::string type_;
};
