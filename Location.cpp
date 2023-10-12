#include "Location.hpp"

#include "Console.hpp"

namespace CPP2
{
    std::string Location::Message() const
    {
        return Title;
    }
    
    std::string Location::Information() const
    {
        return Title + ":" + "\n" +
               "    Merchants: " + "\n" +
               Console.Message(Merchants , 8 , true);
    }
}