#pragma once

#include "String.hpp"

#include <windows.h>

#include <iostream>
#include <vector>

namespace CPP
{
    inline class Console
    {
        private:
            void* Handle;
        public:
            Console();
            void Move(signed short int X , signed short int Y);
            void Print(char Character);
            unsigned long long int Menu(const std::vector<class String>& Entries);
            void Pause();
            void Clear();
    }
    Console;
}