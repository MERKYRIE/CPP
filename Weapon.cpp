#include "Weapon.hpp"

namespace CPP2
{
    std::string Weapon::Message() const
    {
        return Title;
    }

    std::string Weapon::Information() const
    {
        return Title + ":" + "\n" +
               "    Damage: " + std::to_string(Damage);
    }
}