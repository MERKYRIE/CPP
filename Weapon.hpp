#pragma once

#include <iostream>
#include <string>

namespace CPP2
{
    class Weapon
    {
        private:
            friend class Game;
        private:
            std::string Title;
            unsigned long long int Damage;
        public:
            std::string Message() const;
            std::string Information() const;
    };
}