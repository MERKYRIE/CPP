#pragma once

#include "Damages.hpp"
#include "Weapon.hpp"

#include <map>

namespace CPP::Weapons
{
    enum class Type : unsigned long long int
    {
        AntlerAxe ,
    };
    
    inline std::map<Type , _Weapon> Array;

    void Initialize();
}