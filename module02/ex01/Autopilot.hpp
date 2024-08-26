#pragma once

#include "Part.hpp"

class Autopilot : public Part
{
public:
    Autopilot(const std::string& version) : version_(version) {}

    void print() const override {
        std::cout << "Autopilot: Version " << version_ << "\n";
    }

private:
    std::string version_;
};
