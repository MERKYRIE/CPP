#include "Console.hpp"

#include "Keyboard.hpp"

namespace CPP
{
    Console::Console() :
        Handle{GetStdHandle(STD_OUTPUT_HANDLE)}
    {
        
    }

    void Console::Move(signed short int X , signed short int Y)
    {
        CONSOLE_SCREEN_BUFFER_INFO Information;
        GetConsoleScreenBufferInfo(Handle , &Information);
        SetConsoleCursorPosition(Handle , {static_cast<signed short int>(Information.dwCursorPosition.X + X) , static_cast<signed short int>(Information.dwCursorPosition.Y + Y)});
    }

    void Console::Print(char Character)
    {
        std::cout << Character;
        Move(-1 , 0);
    }
    
    unsigned long long int Console::Menu(const std::vector<class String>& Entries)
    {
        for(unsigned long long int Entry{0} ; Entry < Entries.size() ; Entry++)
        {
            std::cout << " " << Entry + 1 << ". " << Entries[Entry] << "\n";
        }
        unsigned long long int Step{1};
        for(char Character : Entries[0])
        {
            if(Character == '\n')
            {
                Step++;
            }
        }
        Move(0 , -static_cast<signed short int>(Entries.size() * Step));
        Print('>');
        unsigned long long int Select{1};
        do
        {
            Keyboard.Update();
            if(Keyboard.Pressed(VK_UP) && Select > 1)
            {
                Select--;
                Print(' ');
                Move(0 , -static_cast<signed short int>(Step));
                Print('>');
            }
            if(Keyboard.Pressed(VK_DOWN) && Select < Entries.size())
            {
                Select++;
                Print(' ');
                Move(0 , static_cast<signed short int>(Step));
                Print('>');
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

    void Console::Pause()
    {
        std::system("Pause");
    }

    void Console::Clear()
    {
        std::system("Clear");
    }
}