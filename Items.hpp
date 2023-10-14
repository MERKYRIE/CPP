#pragma once

#include "Item.hpp"

#include <map>

namespace CPP::Items
{
    enum class Type : unsigned long long int
    {
        Test ,
    };
    
    inline std::map<Type , _Item> Array;

    void Initialize();
}