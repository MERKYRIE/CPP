#pragma once

#include "Location.hpp"
#include "Item.hpp"

#include <iostream>
#include <vector>

namespace CPP
{
    inline class Game
    {
        private:
            std::vector<class Location> Locations;
            unsigned long long int Location;
            std::string Name;
            unsigned long long int Money;
            std::vector<class Item> Inventory;
        public:
            Game();
            void Information();
            void Buy();
            void Sell();
            void Attack();
            void Loot();
    }
    Game;
}