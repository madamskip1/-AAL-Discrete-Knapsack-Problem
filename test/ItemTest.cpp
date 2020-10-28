#define CATCH_CONFIG_MAIN

#include "Item.hpp"
#include "catch.hpp"

TEST_CASE("Basic item test", "[item]")
{
    Item item1 {10, 100};

    REQUIRE(item1.volume == 10);
    REQUIRE(item1.value == 100);

    Item item2 {5, 200};

    REQUIRE(item2.volume == 5);
    REQUIRE(item2.value == 200);

    Item item3;
    item3.volume = 5;
    item3.value = 200;

    REQUIRE(item2 == item3);
    REQUIRE(item1 > item2);

    Item item4 {10, 300};

    REQUIRE(item1 < item4);
}
