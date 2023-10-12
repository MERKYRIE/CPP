#include "Location.hpp"

#include "Console.hpp"

namespace CPP
{
    std::string _Location::Message() const
    {
        return Title;
    }
    
    std::string _Location::Information() const
    {
        return Title + ":" + "\n" +
               "    Stores: " + "\n" +
               Console.Message(Stores , 8 , true);
    }
}