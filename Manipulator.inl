#pragma once

#include "Manipulator.hpp"

namespace CPP
{
    template<typename Type> std::string Spacing(const std::vector<Type>& Vector , bool Additive , unsigned long long int Spacing)
    {
        static unsigned long long int Spaces{0};
        Additive ? Spaces += Spacing : Spaces = Spacing;
        std::string String;
        for(const Type& Value : Vector)
        {
            for(unsigned long long int Space{1} ; Space <= Spaces ; Space++)
            {
                String += " ";
            }
            String += Value.Message() + "\n";
        }
        if(!String.empty())
        {
            String.pop_back();
        }
        return String;
    }
}