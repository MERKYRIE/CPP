#pragma once

#include "Damages.hpp"

#include <string>

namespace CPP
{
    class _Damage
    {
        public:
            unsigned long long int Minimum;
            unsigned long long int Maximum;
            Damages::Type Type;
        public:
            std::string Message() const;
            std::string Information() const;
    };
}