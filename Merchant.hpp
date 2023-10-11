#pragma once

#include "Item.hpp"
#include "String.hpp"

#include <iostream>
#include <string>
#include <vector>

namespace CPP
{
    class Merchant
    {
        private:
            friend class Game;
        private:
            class String Name;
            class String Shop;
            class String Description;
            class String Phrase;
            unsigned long long int Money;
            std::vector<class Item> Inventory;
            bool Dead;
        public:
            class String Message() const;
            void Defend();
            void Looted();
            bool Buy(unsigned long long int& Money);
    };
}