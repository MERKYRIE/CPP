#include "Weapon.hpp"

namespace CPP
{
    std::string Weapon::Message() const
    {
        return Title + ":" + "\n" +
               "                            Description: " + Description + "\n" +
               "                            Weight: " + std::to_string(Weight) + "\n" +
               "                            Damage: " + std::to_string(Damage) + "\n" +
               "                            Cost: " + std::to_string(Cost) + "\n" +
               "                            Durability: " + std::to_string(Durability);
    }

    bool Weapon::Bought(unsigned long long int& Money) const
    {
        if(Money >= Cost)
        {
            Money -= Cost;
            return true;
        }
        else
        {
            return false;
        }
    }
}

std::ostream& operator<<(std::ostream& Stream , const ::CPP::Weapon& Weapon)
{
    Stream << Weapon.Message();
    return Stream;
}