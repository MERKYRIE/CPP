#pragma once

#include "Bonus.hpp"
#include "Damage.hpp"
#include "Item.hpp"

#include <vector>

namespace CPP
{
    class _Weapon : public _Item
    {
        public:
            std::string Type;
            _Damage Damage;
            unsigned long long int Enchant;
            unsigned long long int ToHitArmorClass0;
            std::vector<_Bonus> Special;
            unsigned long long int Speed;
            unsigned long long int Weight;
        public:
            virtual std::string Information() const override;
    };
}