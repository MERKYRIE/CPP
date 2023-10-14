#pragma once

#include "Weaponry.hpp"

#include <map>

namespace CPP::Weaponries
{
    enum class Type : unsigned long long int
    {
        Test ,
    };
    
    inline std::map<Type , _Weaponry> Array;

    void Initialize();
}