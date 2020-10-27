#define CATCH_CONFIG_MAIN

#include <algorithm>
#include <vector>

#include "Knapsack.hpp"
#include "catch.hpp"

template <typename T>
bool compareVectors(std::vector<T> v1, std::vector<T> v2)
{
    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());
    return v1 == v2;
}

TEST_CASE("1st Knapsack - maxAmountOfEachItem", "[max_amount]")
{
    Knapsack knapsack(10, 2);
    knapsack.addItem(2, 13);
    knapsack.addItem(2, 50);
    knapsack.addItem(2, 50);
    knapsack.addItem(2, 50);
    knapsack.addItem(2, 50);
    knapsack.addItem(2, 50);
    knapsack.addItem(2, 50);
    knapsack.addItem(2, 50);
    knapsack.addItem(2, 50);
    knapsack.addItem(2, 50);
    knapsack.addItem(3, 10);
    knapsack.addItem(5, 18);
    knapsack.addItem(6, 22);
    knapsack.addItem(7, 24);
    knapsack.calculateKnapsack();

    std::vector<std::pair<int, int>> expectedKnapsack;

    REQUIRE(knapsack.getResultValue() == 123);

    SECTION("ExpectedKnapsack1")
    {
        expectedKnapsack.push_back(std::make_pair(3, 10));
        expectedKnapsack.push_back(std::make_pair(2, 50));
        expectedKnapsack.push_back(std::make_pair(2, 50));
        expectedKnapsack.push_back(std::make_pair(2, 13));

        REQUIRE(compareVectors(expectedKnapsack, knapsack.getResultKnapsack()));
    }

    SECTION("ExpectedKnapsack2")
    {
        expectedKnapsack.push_back(std::make_pair(2, 50));
        expectedKnapsack.push_back(std::make_pair(3, 10));
        expectedKnapsack.push_back(std::make_pair(2, 50));
        expectedKnapsack.push_back(std::make_pair(2, 13));

        REQUIRE(compareVectors(expectedKnapsack, knapsack.getResultKnapsack()));
    }

    SECTION("ExpectedKnapsack3")
    {
        expectedKnapsack.push_back(std::make_pair(2, 50));
        expectedKnapsack.push_back(std::make_pair(2, 13));
        expectedKnapsack.push_back(std::make_pair(3, 10));
        expectedKnapsack.push_back(std::make_pair(2, 50));

        REQUIRE(compareVectors(expectedKnapsack, knapsack.getResultKnapsack()));
    }
}

TEST_CASE("2nd Knapsack - not full", "[not_full]")
{
    Knapsack knapsack(10, 10);
    knapsack.addItem(2, 10);
    knapsack.addItem(2, 25);
    knapsack.addItem(3, 36);
    knapsack.addItem(4, 70);
    knapsack.addItem(4, 70);
    knapsack.addItem(9, 300);

    knapsack.calculateKnapsack();

    std::vector<std::pair<int, int>> expectedKnapsack;

    REQUIRE(knapsack.getResultValue() == 300);

    expectedKnapsack.push_back(std::make_pair(9, 300));

    REQUIRE(compareVectors(expectedKnapsack, knapsack.getResultKnapsack()));
}

TEST_CASE("3nd Knapsack - all items heavier then capacity", "[heavier]")
{
    Knapsack knapsack(10, 10);
    knapsack.addItem(32, 10);
    knapsack.addItem(72, 25);
    knapsack.addItem(13, 36);
    knapsack.addItem(84, 70);
    knapsack.addItem(884, 70);
    knapsack.addItem(889, 300);

    knapsack.calculateKnapsack();

    std::vector<std::pair<int, int>> expectedKnapsack;

    REQUIRE(knapsack.getResultValue() == 0);
    REQUIRE(compareVectors(expectedKnapsack, knapsack.getResultKnapsack()));
}

TEST_CASE("4th - more then one result's vector", "[more_results]")
{
    // {5*2, 2*5, 1*10} may be {{2, 2, 2, 2, 2}, {5, 5}, {10}}, so just check value

    Knapsack knapsack(10, 5);
    knapsack.addItem(2, 2);
    knapsack.addItem(2, 2);
    knapsack.addItem(2, 2);
    knapsack.addItem(2, 2);
    knapsack.addItem(2, 2);
    knapsack.addItem(5, 5);
    knapsack.addItem(5, 5);
    knapsack.addItem(10, 10);

    knapsack.calculateKnapsack();

    REQUIRE(knapsack.getResultValue() == 10);
}

TEST_CASE("5th - different order of input", "[input_order]")
{
    // [{2, 13}, {3, 10}, {5, 18}, {6, 22}, {7, 24}] => 45

    Knapsack knapsack(11, 4);
    std::vector<std::pair<int, int>> expectedKnapsack;
    expectedKnapsack.push_back(std::make_pair(2, 13));
    expectedKnapsack.push_back(std::make_pair(3, 10));
    expectedKnapsack.push_back(std::make_pair(6, 22));

    SECTION("First order")
    {
        knapsack.addItem(2, 13);
        knapsack.addItem(3, 10);
        knapsack.addItem(5, 18);
        knapsack.addItem(6, 22);
        knapsack.addItem(7, 24);

        knapsack.calculateKnapsack();

        REQUIRE(knapsack.getResultValue() == 45);
        REQUIRE(compareVectors(expectedKnapsack, knapsack.getResultKnapsack()));
    }

    SECTION("Second order")
    {
        knapsack.addItem(5, 18);
        knapsack.addItem(3, 10);
        knapsack.addItem(7, 24);
        knapsack.addItem(2, 13);
        knapsack.addItem(6, 22);

        knapsack.calculateKnapsack();

        REQUIRE(knapsack.getResultValue() == 45);
        REQUIRE(compareVectors(expectedKnapsack, knapsack.getResultKnapsack()));
    }

    SECTION("Third order")
    {
        knapsack.addItem(6, 22);
        knapsack.addItem(7, 24);
        knapsack.addItem(3, 10);
        knapsack.addItem(5, 18);
        knapsack.addItem(2, 13);
        knapsack.calculateKnapsack();

        REQUIRE(knapsack.getResultValue() == 45);
        REQUIRE(compareVectors(expectedKnapsack, knapsack.getResultKnapsack()));
    }
}

TEST_CASE("No items", "[no_items]")
{
    Knapsack knapsack(10, 2);

    knapsack.calculateKnapsack();

    REQUIRE(knapsack.getResultValue() == 0);
    REQUIRE(knapsack.getResultKnapsack().empty());
}

TEST_CASE("Weightless items", "[weightless]")
{
    Knapsack knapsack(10, 10);
    knapsack.addItem(0, 5);
    knapsack.addItem(0, 1);
    knapsack.addItem(0, 10);
    knapsack.addItem(11, 11);
    knapsack.addItem(5, 10);
    knapsack.addItem(6, 10);
    knapsack.addItem(3, 10);

    knapsack.calculateKnapsack();

    std::vector<std::pair<int, int>> expectedKnapsack;
    expectedKnapsack.push_back(std::make_pair(0, 5));
    expectedKnapsack.push_back(std::make_pair(0, 1));
    expectedKnapsack.push_back(std::make_pair(0, 10));
    expectedKnapsack.push_back(std::make_pair(5, 10));
    expectedKnapsack.push_back(std::make_pair(3, 10));

    REQUIRE(knapsack.getResultValue() == 36);
    REQUIRE(compareVectors(expectedKnapsack, knapsack.getResultKnapsack()));
}

TEST_CASE("Valueless items", "[valueless]")
{
    Knapsack knapsack(10, 10);
    knapsack.addItem(0, 0);
    knapsack.addItem(1, 0);
    knapsack.addItem(2, 0);
    knapsack.addItem(11, 11);
    knapsack.addItem(5, 10);
    knapsack.addItem(6, 10);
    knapsack.addItem(3, 10);

    knapsack.calculateKnapsack();

    std::vector<std::pair<int, int>> expectedKnapsack;
    expectedKnapsack.push_back(std::make_pair(5, 10));
    expectedKnapsack.push_back(std::make_pair(3, 10));

    REQUIRE(knapsack.getResultValue() == 20);
    REQUIRE(compareVectors(expectedKnapsack, knapsack.getResultKnapsack()));
}
