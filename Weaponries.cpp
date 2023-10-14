#include "Weaponries.hpp"

#include "Weapons.hpp"

namespace CPP::Weaponries
{
    void Initialize()
    {
        Array[Type::Test].Title = "Test";
        Array[Type::Test].Type = "Weaponry";
        Array[Type::Test].Money = 1'000'000;
        for(auto& [Type , Item] : Weapons::Array)
        {
            Array[Type::Test].Inventory.push_back(&Item);
        }
        Array[Type::Test].Dead = false;
    }
}