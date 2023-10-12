#include "Weapons.hpp"

namespace CPP::Weapons
{
    void Initialize()
    {
        Array[Type::AntlerAxe].Title = "Antler Axe";
        Array[Type::AntlerAxe].Cost = 3;
        Array[Type::AntlerAxe].Type = "Axe";
        Array[Type::AntlerAxe].Damage.Minimum = 2;
        Array[Type::AntlerAxe].Damage.Maximum = 7;
        Array[Type::AntlerAxe].Damage.Type = Damages::Type::Slashing;
        Array[Type::AntlerAxe].Enchant = 0;
        Array[Type::AntlerAxe].ToHitArmorClass0 = 0;
        Array[Type::AntlerAxe].Special = {};
        Array[Type::AntlerAxe].Speed = 8;
        Array[Type::AntlerAxe].Weight = 8;
    }
}