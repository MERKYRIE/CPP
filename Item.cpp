#include "Item.hpp"

namespace CPP
{
    std::string _Item::Message() const
    {
        return Title;
    }
    
    std::string _Item::Information() const
    {
        return Title + ":" + "\n" +
               "    Cost: " + std::to_string(Cost);
    }
}