#pragma once

#include <iostream>

class ACar
{
protected:
    std::string _make;
    std::string _model;
    std::string _year;
public:
    ACar();
    ACar(const std::string& make, const std::string& model, const std::string& year);
    ACar(const ACar &other);
    ACar &operator=(const ACar &other);
    virtual ~ACar();

    void setMake(std::string make);
    void setModel(std::string model);
    void setYear(std::string year);

    std::string getMake() const;
    std::string getModel() const;
    std::string getYear() const;

    virtual void displayInfo() const = 0;
};
