#pragma once

#include "Store.hpp"

#include <iostream>
#include <vector>

namespace CPP
{
    class _Location
    {
        public:
            std::string Title;
            std::vector<unsigned long long int> Transitions;
            std::vector<_Store*> Stores;
        public:
            std::string Message() const;
            std::string Information() const;
    };
}