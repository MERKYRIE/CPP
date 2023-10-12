#pragma once

#include <iostream>

namespace CPP2
{
    class Character
    {
        private:
            friend class Game;
        private:
            std::string Name;
        public:
            std::string Message() const;
            std::string Information() const;
    };
}