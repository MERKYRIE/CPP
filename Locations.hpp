#pragma once

#include "Location.hpp"

#include <map>

namespace CPP::Locations
{
    enum class Type : unsigned long long int
    {
        Test ,
    };
    
    inline std::map<Type , _Location> Array;

    void Initialize();
}