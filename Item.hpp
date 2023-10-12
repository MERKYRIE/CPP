#pragma once

#include <iostream>
#include <string>

namespace CPP2
{
    class Item
    {
        private:
            friend class Game;
        private:
            std::string Title;
            unsigned long long int Cost;
        public:
            std::string Message() const;
            std::string Information() const;
    };
}