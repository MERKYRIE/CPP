#pragma once

#include "Store.hpp"

#include <map>

namespace CPP::Stores
{
    enum class Type : unsigned long long int
    {
        Test ,
    };
    
    inline std::map<Type , _Store> Array;

    void Initialize();
}