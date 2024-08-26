#pragma once

#include <iostream>

class Part
{
public:
    virtual ~Part() = default;
    virtual void print() const = 0;
};
