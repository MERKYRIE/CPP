#pragma once

#include "Attribute.hpp"

#include <string>

namespace CPP
{
    class _Bonus
    {
        public:
            _Attribute Attribute;
        public:
            std::string Message() const;
            std::string Information() const;
    };
}