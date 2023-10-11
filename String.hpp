#pragma once

#include <iostream>
#include <vector>

namespace CPP
{
    class String : public std::string
    {
        public:
            template<typename Type> String operator+(const Type& Value);
            inline String Information(unsigned long long int Spacing);
    };
}

#include "String.inl"