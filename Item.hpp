#pragma once

#include <string>

namespace CPP
{
    class _Item
    {
        public:
            std::string Title;
            unsigned long long int Cost;
        public:
            virtual std::string Message() const;
            virtual std::string Information() const;
    };
}