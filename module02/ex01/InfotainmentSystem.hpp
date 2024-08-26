#pragma once

#include "Part.hpp"

class InfotainmentSystem : public Part
{
public:
    InfotainmentSystem(const std::string& version) : version_(version) {}

    void print() const override {
        std::cout << "Infotainment System: Version " << version_ << "\n";
    }

private:
    std::string version_;
};
