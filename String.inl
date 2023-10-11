#pragma once

#include "String.hpp"

namespace CPP
{
    template<typename Type> String String::operator+(const Type& Value)
    {
        return *this + Value;
    }
    
    inline String String::Information(unsigned long long int Spacing)
    {
        String String{*this};
        String.insert(0 , Spacing , ' ');
        for(unsigned long long int Character{Spacing} ; Character < String.size() ; Character++)
        {
            if(String[Character] == '\n')
            {
                String.insert(Character + 1 , Spacing , ' ');
                Character += Spacing;
            }
        }
        return String;
    }
}