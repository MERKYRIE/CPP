#pragma once

#include "String.hpp"

#include <iostream>
#include <string>

namespace CPP
{
    class Item
    {
        private:
            friend class Game;
        private:
            class String Title;
            unsigned long long int Cost;
        public:
            class String Message() const;
    };
}