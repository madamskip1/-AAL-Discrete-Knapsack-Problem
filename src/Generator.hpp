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

    // Rozk�ad normalny dla warto�ci przedmiot�w - �rednia warto�� ka�dego 50% maxValue
    const float binominalParameterValueDistr = 0.5;
    // Parametr 0.02 w rozk�adzie sprawi, �e maksymalna ilo�� poszczeg�lnych przedmiot�w b�dzie na poziomie 2% wszystkich
    const float binominalParameterMaxDuplicates = 0.02;
    // Parametr 0.5 rozk�adu sprawi, �e pojemno�� b�dzie �rednio 5 razy wi�ksza ni� ilo�� przedmiot�w
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