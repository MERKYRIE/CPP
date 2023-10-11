#pragma once

#include <windows.h>

#include <vector>

namespace CPP
{
    inline class _Keyboard
    {
        private:
            std::vector<std::uint8_t> _Last;
            std::vector<std::uint8_t> _State;
        public:
            _Keyboard();
            void Update();
            bool Pressed(std::uint8_t Key);
    }
    Keyboard;
}