#include "ACar.hpp"

ACar::ACar() : _make("ACar"), _model("Model"), _year("Year") {}

ACar::~ACar() {}

ACar::ACar(const ACar &other) : _make(other._make), _model(other._model), _year(other._year) {}

ACar::ACar(const std::string& make, const std::string& model, const std::string& year)
    : _make(make), _model(model), _year(year) {}

ACar &ACar::operator=(const ACar &other)
{
    if (this == &other)
        return *this;
    _make = other._make;
    _model = other._model;
    _year = other._year;
    return *this;
}

void ACar::setMake(std::string make)
{
    _make = make;
}

void ACar::setModel(std::string model)
{
    _model = model;
}

void ACar::setYear(std::string year)
{
    _year = year;
}

std::string ACar::getMake() const
{
    return _make;
}

std::string ACar::getModel() const
{
    return _model;
}

std::string ACar::getYear() const
{
    return _year;
}
