#include "Generator.hpp"
const float Generator::DEFAULT_BINOMINAL_PARAMETER = 0.1;

Generator::Generator(int numItems)
    : numItems(numItems)
{
    binominalParameter = Generator::DEFAULT_BINOMINAL_PARAMETER;
    calcCapacity();
    calcMaxDuplicates();
}

int Generator::getCapacity()
{
    return capacity;
}

int Generator::getMaxDuplciates()
{
    return maxDuplicates;
}

void Generator::setBinominalParameter(float binominal)
{
    binominalParameter = binominal;
}

void Generator::setMaxDuplicates(int maxNumber)
{
    maxDuplicates = maxNumber;
}

void Generator::setCapacity(int capacity)
{
    this->capacity = capacity;
}

std::vector<Item> Generator::generate()
{
    std::vector<Item> items;
    int volume, value;
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());

    // Rozk³ad normalny wagi przedmiotów, domyœlnie 10% maksymalnej pojemnoœci
    std::binomial_distribution<> volumeDistribution(capacity, binominalParameter);
    std::binomial_distribution<> valueDistribution(itemMaxValue, binominalParameterValueDistr);

    for (int i = 0; i < numItems; i++)
    {
        volume = volumeDistribution(gen);
        value = valueDistribution(gen);

        items.push_back(Item(volume, value));
    }

    return items;
}

void Generator::calcMaxDuplicates()
{
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());
    std::binomial_distribution<> maxNumberDistribution(numItems, binominalParameterMaxDuplicates);

    maxDuplicates = maxNumberDistribution(gen);
}

void Generator::calcCapacity()
{
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());

    int maxCapacity = numItems * 10;
    // Parametr 0.5 rozk³adu sprawi, ¿e pojemnoœæ bêdzie œrednio 5 razy wiêksza ni¿ iloœæ przedmiotów
    std::binomial_distribution<> capacityDistribution(maxCapacity, 0.5);

    capacity = capacityDistribution(gen);
}