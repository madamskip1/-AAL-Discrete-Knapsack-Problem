#pragma once

#include <iostream>

struct Item
{
    int volume;
    int value;

    Item(int volume_, int value_)
        : volume(volume_)
        , value(value_) {};
    Item()
        : volume(0)
        , value(0) {};

    bool operator==(Item const &x) const
    {
        return this->volume == x.volume && this->value == x.value;
    }

    bool operator<(Item const &x) const
    {
        return this->volume == x.volume ? this->value < x.value : this->volume < x.volume;
    }

    bool operator>(Item const &x) const
    {
        return this->volume == x.volume ? this->value > x.value : this->volume > x.volume;
    }

    friend std::ostream &operator<<(std::ostream &os, const Item &x)
    {
        return os << x.volume << " " << x.value;
    }
};
