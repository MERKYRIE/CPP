#pragma once

#include "Item.hpp"

#include <vector>

namespace CPP
{
    class _Store
    {
        public:
            std::string Title;
            std::string Type;
            unsigned long long int Money;
            std::vector<_Item*> Inventory;
            bool Dead;
        public:
            _Store(const std::string& Title);
            virtual std::string Message() const;
            virtual std::string Information() const;
    };
}