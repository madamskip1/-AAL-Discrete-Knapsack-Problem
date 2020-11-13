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

    // Rozk³ad normalny dla wartoœci przedmiotów - œrednia wartoœæ ka¿dego 50% maxValue
    const float binominalParameterValueDistr = 0.5;
    // Parametr 0.02 w rozk³adzie sprawi, ¿e maksymalna iloœæ poszczególnych przedmiotów bêdzie na poziomie 2% wszystkich
    const float binominalParameterMaxDuplicates = 0.02;
    // Parametr 0.5 rozk³adu sprawi, ¿e pojemnoœæ bêdzie œrednio 5 razy wiêksza ni¿ iloœæ przedmiotów
    const float binominalParameterCapacity = 0.5;
    const int itemMaxValue = 100;

    void calcMaxDuplicates();
    void calcCapacity();
    Generator();

public:
    static const float DEFAULT_BINOMINAL_PARAMETER;
    Generator(int numItems);
    int getCapacity();
    int getMaxDuplciates();
    void setBinominalParameter(float binominal);
    void setCapacity(int capacity);
    std::vector<Item> generate();
};