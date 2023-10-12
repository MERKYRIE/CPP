#pragma once

#include "Keyboard.hpp"

#include <windows.h>

#include <iostream>
#include <vector>

namespace CPP2
{
    inline class Console
    {
        private:
            void* Handle;
        public:
            inline Console();
            inline void Clear();
            inline void Pause();
            inline void Seek(signed short int X , signed short int Y);
            inline void Put(char Character);
            inline std::string Parse(const std::string& String , unsigned long long int Spacing , bool Prefix);
            template<typename Type> std::string Message(const Type& Value , unsigned long long int Spacing , bool Prefix);
            template<typename Type> std::string Message(const std::vector<Type>& Vector , unsigned long long int Spacing , bool Prefix);
            template<typename Type> std::string Information(const Type& Value , unsigned long long int Spacing , bool Prefix);
            template<typename Type> std::string Information(const std::vector<Type>& Vector , unsigned long long int Spacing , bool Prefix);
            inline unsigned long long int Menu(const std::vector<std::string>& Entries);
            template<typename Type> unsigned long long int Menu(const std::vector<std::string>& Entries , const std::vector<Type>& Options);
    }
    Console;
}

#include "Console.inl"