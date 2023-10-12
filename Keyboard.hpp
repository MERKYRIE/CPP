#pragma once

#include <windows.h>

#include <vector>

namespace CPP
{
    inline class _Keyboard
    {
        private:
            std::vector<unsigned char> _Last;
            std::vector<unsigned char> _State;
        public:
            _Keyboard();
            void Update();
            bool Pressed(unsigned char Key);
    }
    Keyboard;
}