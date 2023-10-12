#pragma once

#include "Item.hpp"

#include <iostream>
#include <string>
#include <vector>

namespace CPP2
{
    class Merchant
    {
        private:
            friend class Game;
        private:
            std::string Name;
            std::string Shop;
            std::string Description;
            std::string Phrase;
            unsigned long long int Money;
            std::vector<class Item> Inventory;
            bool Dead;
        public:
            std::string Message() const;
            std::string Information() const;
    };
}