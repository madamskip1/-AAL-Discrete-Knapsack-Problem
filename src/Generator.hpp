#pragma once
#include <vector>
#include <random>

#include "Item.hpp"
class Generator
{
    int numItems;
    int capacity;
    int maxDuplicates;
    float binominalParameter;

    void calcMaxNumberOfItem();
    void calcCapacity();
    Generator();

public:
    static const float DEFAULT_BINOMINAL_PARAMETER;

    Generator(int numItems);
    int getCapacity();
    int getMaxDuplciates();
    void setBinominalParameter(float binominal);
    void setMaxDuplicates(int maxNumber);
    void setCapacity(int capacity);
    std::vector<Item> generate();
};