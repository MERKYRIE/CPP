#pragma once

#include <string>
#include <map>

namespace CPP::Damages
{
    enum class Type : unsigned long long int
    {
        Slashing ,
        Piercing ,
        Crushing ,
    };
    
    inline std::map<Type , std::string> Array;

    void Initialize();
}