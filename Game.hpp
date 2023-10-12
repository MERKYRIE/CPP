#pragma once

#include "Location.hpp"
#include "Item.hpp"
#include "Weapon.hpp"

#include <iostream>
#include <vector>

namespace CPP2
{
    inline class Game
    {
        private:
            std::vector<class Location> Locations;
            std::string Name;
            unsigned long long int Location;
            unsigned long long int Money;
            std::vector<class Item> Inventory;
            class Weapon Weapon;
        public:
            Game();
            void Inspect();
            void Buy();
            void Sell();
            void Attack();
            void Loot();
            void Travel();
            void Speak();
    }
    Game;
}