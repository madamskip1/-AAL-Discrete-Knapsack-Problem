#pragma once

#include <random>
#include <vector>

#include "Item.hpp"
class Generator
{
    int numItems;
    int capacity;
    int maxDuplicates;
    float binominalParameter;

    const float binominalParameterValueDistr = 0.5f;
    const float binominalParameterMaxDuplicates = 0.02f;
    const float binominalParameterCapacity = 0.5f;
    const int itemMaxValue = 100;

    void calcMaxDuplicates();
    void calcCapacity();
    Generator();

public:
    static const float DEFAULT_BINOMINAL_PARAMETER;
    Generator(int numItems);
    int getCapacity();
    int getMaxDuplicates();
    void setBinominalParameter(float binominal);
    void setCapacity(int capacity);
    std::vector<Item> generate();
};
