#pragma once

#include <string>

namespace CPP
{
    class _Attribute
    {
        public:
            std::string Title;
            unsigned long long int Value;
        public:
            std::string Message() const;
            std::string Information() const;
    };
}