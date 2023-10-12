#include "Weaponry.hpp"

#include "Weapons.hpp"

namespace CPP
{
    _Weaponry::_Weaponry(const std::string& Title) : _Store{Title}
    {
        Type = "Weaponry";
        for(std::map<Weapons::Type , _Weapon>::iterator Weapon{Weapons::Array.begin()} ; Weapon < Weapons::Array.end() ; Weapon++)
        {
            Inventory.push_back(Weapon);
        }
    }
}