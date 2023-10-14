#include "Stores.hpp"

#include "Items.hpp"

namespace CPP::Stores
{
    void Initialize()
    {
        Array[Type::Test].Title = "Test";
        Array[Type::Test].Type = "Store";
        Array[Type::Test].Money = 1'000'000;
        for(auto& [Type , Item] : Items::Array)
        {
            Array[Type::Test].Inventory.push_back(&Item);
        }
        Array[Type::Test].Dead = false;
    }
}