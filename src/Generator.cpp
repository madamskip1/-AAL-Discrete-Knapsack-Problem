#include "Generator.hpp"
const float Generator::DEFAULT_BINOMINAL_PARAMETER = 0.1;

Generator::Generator(int numItems)
    : numItems(numItems)
{
    binominalParameter = Generator::DEFAULT_BINOMINAL_PARAMETER;
    calcCapacity();
    calcMaxNumberOfItem();
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
    int max_value;
    std::vector<Item> items;
    int volume, value;
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());

    // Rozk³ad normalny wagi przedmiotów, domyœlnie 10% maksymalnej pojemnoœci
    std::binomial_distribution<> volumeDistribution(capacity, binominalParameter);

    // Rozk³ad normalny dla wartoœci przedmiotów - œrednia wartoœæ ka¿dego 50
    std::binomial_distribution<> valueDistribution(100, 0.5);

    for (int i = 0; i < numItems; i++)
    {
        volume = volumeDistribution(gen);
        value = valueDistribution(gen);

        items.push_back(Item(volume, value));
    }

    return items;
}

void Generator::calcMaxNumberOfItem()
{
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());
    // Parametr 0.02 w rozk³adzi sprawi, ¿e maksymalna iloœæ poszczególnych przedmiotów bêdzie na poziomie 2% wszystkich
    std::binomial_distribution<> maxNumberDistribution(numItems, 0.02);

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