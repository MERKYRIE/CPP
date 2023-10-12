#pragma once

#include "Character.hpp"
#include "Merchant.hpp"

#include <iostream>
#include <vector>

namespace CPP2
{
    class Location
    {
        private:
            friend class Game;
        private:
            std::string Title;
            std::vector<unsigned long long int> Transitions;
            std::vector<Merchant> Merchants;
            std::vector<Character> Characters;
        public:
            std::string Message() const;
            std::string Information() const;
    };
}