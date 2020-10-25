#include "FileStreamRunMode.h"

FileStreamRunMode::FileStreamRunMode(std::string inputFileName, std::string outputFileName) : RunMode(), inputFileName(inputFileName), outputFileName(outputFileName)
{
	knapsack = nullptr;
}

FileStreamRunMode::~FileStreamRunMode()
{
	closeFiles();
	delete knapsack;
}

void FileStreamRunMode::run()
{
	openFiles();
	readInputFile();
	std::cout << "Obliczanie wyniku..." << std::endl;
	knapsack->calculateKnapsack();
	std::cout << "Obliczono wynik." << std::endl;
	writeOutputFile();
	closeFiles();
}

void FileStreamRunMode::openFiles()
{
	inputFile.open(inputFileName, std::ios::in|std::ios::binary);
	if (inputFile.fail())
	{
		// TODO: wyj¹tek, nie otworzono pliku
	}

	outputFile.open(outputFileName);
	if (outputFile.fail())
	{
		// TODO: wyj¹tek, nie otworzono pliku
	}

}

void FileStreamRunMode::closeFiles()
{
	inputFile.close();
	outputFile.close();
}

void FileStreamRunMode::readInputFile()
{
	std::cout << "Odczytywanie danych wejsciowych..." << std::endl;
	int capacity;
	int maxAmountOfEachItem;
	int volume, value;
	inputFile >> capacity;
	inputFile >> maxAmountOfEachItem;
	knapsack = new Knapsack(capacity, maxAmountOfEachItem);

	while (inputFile >> volume >> value)
	{
		knapsack->addItem(volume, value);
	}

	std::cout << "Zakonczono odczytywanie danych wejsciowych." << std::endl;
}

void FileStreamRunMode::writeOutputFile()
{
	std::cout << "Zapisywanie wyniku do pliku..." << std::endl;
	outputFile << knapsack->getResultValue() << std::endl;
	
	for (const std::pair<int, int>& item : knapsack->getResultKnapsack())
	{
		outputFile << item.first << " " << item.second << std::endl;
	}
	std::cout << "Zapisano dane do pliku." << std::endl;
}

