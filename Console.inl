#pragma once

#include "Console.hpp"

namespace CPP2
{
    inline Console::Console() :
        Handle{GetStdHandle(STD_OUTPUT_HANDLE)}
    {
        
    }

    inline void Console::Clear()
    {
        std::system("Clear");
    }

    inline void Console::Pause()
    {
        std::system("Pause");
    }

    inline void Console::Seek(signed short int X , signed short int Y)
    {
        CONSOLE_SCREEN_BUFFER_INFO Information;
        GetConsoleScreenBufferInfo(Handle , &Information);
        SetConsoleCursorPosition(Handle , {static_cast<signed short int>(Information.dwCursorPosition.X + X) , static_cast<signed short int>(Information.dwCursorPosition.Y + Y)});
    }

    inline void Console::Put(char Character)
    {
        std::cout << Character;
        Seek(-1 , 0);
    }

    inline std::string Console::Parse(const std::string& String , unsigned long long int Spacing , bool Prefix)
    {
        std::string Spaced{String};
        if(Prefix)
        {
            Spaced.insert(0 , Spacing , ' ');
        }
        for(unsigned long long int Character{Spacing} ; Character < Spaced.size() ; Character++)
        {
            if(Spaced[Character] == '\n')
            {
                Spaced.insert(Character + 1 , Spacing , ' ');
                Character += Spacing;
            }
        }
        return Spaced;
    }

    template<typename Type> std::string Console::Message(const Type& Value , unsigned long long int Spacing , bool Prefix)
    {
        return Parse(Value.Message() , Spacing , Prefix);
    }

    template<typename Type> std::string Console::Information(const Type& Value , unsigned long long int Spacing , bool Prefix)
    {
        return Parse(Value.Information() , Spacing , Prefix);
    }

    template<typename Type> std::string Console::Message(const std::vector<Type>& Vector , unsigned long long int Spacing , bool Prefix)
    {
        std::string String;
        for(const Type& Value : Vector)
        {
            String += Message(Value , Spacing , Prefix) + "\n";
        }
        if(!String.empty())
        {
            String.pop_back();
        }
        return String;
    }

    template<typename Type> std::string Console::Information(const std::vector<Type>& Vector , unsigned long long int Spacing , bool Prefix)
    {
        std::string String;
        for(const Type& Value : Vector)
        {
            String += Information(Value , Spacing , Prefix) + "\n";
        }
        if(!String.empty())
        {
            String.pop_back();
        }
        return String;
    }

    inline unsigned long long int Console::Menu(const std::vector<std::string>& Entries)
    {
        for(unsigned long long int Entry{0} ; Entry < Entries.size() ; Entry++)
        {
            std::cout << " " << Entry + 1 << ". " << Parse(Entries[Entry] , 4 , false) << "\n";
        }
        unsigned long long int Step{1};
        for(char Character : Entries[0])
        {
            if(Character == '\n')
            {
                Step++;
            }
        }
        Seek(0 , -static_cast<signed short int>(Entries.size() * Step));
        Put('>');
        unsigned long long int Select{1};
        do
        {
            Keyboard.Update();
            if(Keyboard.Pressed(VK_UP) && Select > 1)
            {
                Select--;
                Put(' ');
                Seek(0 , -static_cast<signed short int>(Step));
                Put('>');
            }
            if(Keyboard.Pressed(VK_DOWN) && Select < Entries.size())
            {
                Select++;
                Put(' ');
                Seek(0 , static_cast<signed short int>(Step));
                Put('>');
            }
            if(Keyboard.Pressed(VK_RETURN))
            {
                for(unsigned long long int Enter{1} ; Enter <= (Entries.size() - Select + 1) * Step + 1 ; Enter++)
                {
                    std::cout << "\n";
                }
                return Select;
            }
        }
        while(!Keyboard.Pressed(VK_ESCAPE));
        for(unsigned long long int Enter{1} ; Enter <= (Entries.size() - Select + 1) * Step + 1 ; Enter++)
        {
            std::cout << "\n";
        }
        return 0;
    }

    template<typename Type> unsigned long long int Console::Menu(const std::vector<std::string>& Entries , const std::vector<Type>& Options)
    {
        for(unsigned long long int Entry{0} ; Entry < Entries.size() ; Entry++)
        {
            std::cout << " " << Entry + 1 << ". " << Parse(Entries[Entry] , 4 , false) << "\n";
        }
        unsigned long long int Step{1};
        for(char Character : Entries[0])
        {
            if(Character == '\n')
            {
                Step++;
            }
        }
        Seek(0 , -static_cast<signed short int>(Entries.size() * Step));
        Put('>');
        unsigned long long int Select{1};
        do
        {
            Keyboard.Update();
            if(Keyboard.Pressed(VK_UP) && Select > 1)
            {
                Select--;
                Put(' ');
                Seek(0 , -static_cast<signed short int>(Step));
                Put('>');
            }
            if(Keyboard.Pressed(VK_DOWN) && Select < Entries.size())
            {
                Select++;
                Put(' ');
                Seek(0 , static_cast<signed short int>(Step));
                Put('>');
            }
            if(Keyboard.Pressed(VK_RETURN))
            {
                for(unsigned long long int Enter{1} ; Enter <= (Entries.size() - Select + 1) * Step + 1 ; Enter++)
                {
                    std::cout << "\n";
                }
                return Options[Select - 1];
            }
        }
        while(!Keyboard.Pressed(VK_ESCAPE));
        for(unsigned long long int Enter{1} ; Enter <= (Entries.size() - Select + 1) * Step + 1 ; Enter++)
        {
            std::cout << "\n";
        }
        return 0;
    }
}