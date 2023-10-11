#pragma once

#include <iostream>
#include <string>

namespace CPP
{
    class Weapon
    {
        private:
            friend class Game;
        private:
            std::string Title;
            std::string Description;
            unsigned long long int Weight;
            unsigned long long int Damage;
            unsigned long long int Cost;
            double Durability;
        public:
            std::string Message() const;
            bool Bought(unsigned long long int& Money) const;
    };
}

std::ostream& operator<<(std::ostream& Stream , const ::CPP::Weapon& Weapon);