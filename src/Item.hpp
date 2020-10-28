#pragma once

struct Item
{
    int value;
    int volume;

    bool operator==(Item const &x) const
    {
        return this->value == x.value && this->volume == x.volume;
    }

    bool operator<(Item const &x) const
    {
        return this->value == x.value ? this->volume < x.volume : this->value < x.value;
    }
};
