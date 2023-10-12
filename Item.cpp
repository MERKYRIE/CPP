#include "Item.hpp"

namespace CPP2
{
    std::string Item::Message() const
    {
        return Title;
    }
    
    std::string Item::Information() const
    {
        return Title + ":" + "\n" +
               "    Cost: " + std::to_string(Cost);
    }
}