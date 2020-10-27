#include <iostream>
#include <vector>

#include "FileStreamRunMode.hpp"
#include "Knapsack.hpp"

void m1Mode(int argc, char *argv[])
{
    std::cout << "Wybrano tryb uruchomienia M1 - Input/Output - pliki." << std::endl;

    if (argc < 4)
    {
        std::cout << "Podano za mala liczbe parametrow dla tego trybu." << std::endl;
        std::cout << "Wymagane dwa parametry:" << std::endl << "* nazwa pliku z danymi wejsciowymi" << std::endl << "* nazwa pliku wynikowego" << std::endl;

        return;
    }

    std::string inFileName = argv[2];
    std::string outFileName = argv[3];

    std::cout << "Nazwa pliku z danymi wejsciowymi: " << inFileName << std::endl;
    std::cout << "Nazwa pliku wynikowego: " << outFileName << std::endl;

    FileStreamRunMode runMode("in.txt", "out.txt");
    runMode.run();
}

void m2Mode(int argc, char *argv[])
{
    // TODO
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "Nie wybrano trybu uruchomienia." << std::endl;
        return 1;
    }

    if (argv[1] == std::string("-m1"))
    {
        m1Mode(argc, argv);
    }
    else if (argv[1] == std::string("-m2"))
    {
        m2Mode(argc, argv);
    }
    else
    {
        std::cout << "Wybrano nieistniejacy tryb uruchomienia." << std::endl;
        return 1;
    }

    return 0;
}
