#pragma once

struct Item
{
    int volume;
    int value;

    bool operator==(Item const &x) const
    {
        return this->volume == x.volume && this->value == x.value;
    }

    bool operator<(Item const &x) const
    {
        return this->volume == x.volume ? this->value < x.value : this->volume < x.volume;
    }
};
