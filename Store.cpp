#include "Store.hpp"

#include "Console.hpp"
#include "Items.hpp"

namespace CPP
{
    _Store::_Store(const std::string& Title) : Title{Title}
    {
        Type = "Store";
        Money = 1'000'000;
        for(_Item& Item : Items)
        {
            Inventory.push_back(&Item);
        }
        Dead = false;
    }
    
    std::string _Store::Message() const
    {
        return Title;
    }
    
    std::string _Store::Information() const
    {
        return Title + ":" + "\n" +
               "    Type: " + Type + "\n"
               "    Money: " + std::to_string(Money);
    }
}