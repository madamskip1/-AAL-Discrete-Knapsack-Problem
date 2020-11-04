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

    // Rozk�ad normalny wagi przedmiot�w, domy�lnie 10% maksymalnej pojemno�ci
    std::binomial_distribution<> volumeDistribution(capacity, binominalParameter);

    // Rozk�ad normalny dla warto�ci przedmiot�w - �rednia warto�� ka�dego 50
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
    // Parametr 0.02 w rozk�adzi sprawi, �e maksymalna ilo�� poszczeg�lnych przedmiot�w b�dzie na poziomie 2% wszystkich
    std::binomial_distribution<> maxNumberDistribution(numItems, 0.02);

    maxDuplicates = maxNumberDistribution(gen);
}

void Generator::calcCapacity()
{
    std::random_device randomDevice;
    std::mt19937 gen(randomDevice());

    int maxCapacity = numItems * 10;
    // Parametr 0.5 rozk�adu sprawi, �e pojemno�� b�dzie �rednio 5 razy wi�ksza ni� ilo�� przedmiot�w
    std::binomial_distribution<> capacityDistribution(maxCapacity, 0.5);

    capacity = capacityDistribution(gen);
}