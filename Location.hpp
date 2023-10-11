#pragma once

#include "Merchant.hpp"

#include <iostream>
#include <vector>

namespace CPP
{
    class Location
    {
        private:
            friend class Game;
        private:
            std::string Title;
            std::vector<Merchant> Merchants;
        public:
            std::string Message() const;
    };
}