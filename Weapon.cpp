#include "Weapon.hpp"

#include "Console.hpp"

namespace CPP
{
    std::string _Weapon::Information() const
    {
        return _Item::Information() + "\n" +
               "    Type: " + Type + "\n" +
               "    Damage: " + "\n" +
               Console.Information(Damage , 8 , true) + "\n" +
               "    Enchant: " + std::to_string(Enchant) + "\n" +
               "    ToHitArmorClass0: " + std::to_string(ToHitArmorClass0) + "\n" +
               "    Special: " + "\n" +
               (Special.empty() ? "" : Console.Information(Special , 8 , true) + "\n") +
               "    Speed: " + std::to_string(Speed) + "\n"
               "    Weight: " + std::to_string(Weight);
    }
}