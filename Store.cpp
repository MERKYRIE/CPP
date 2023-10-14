#include "Store.hpp"

namespace CPP
{
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