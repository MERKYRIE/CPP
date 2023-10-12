#include "Merchant.hpp"

#include "Console.hpp"

namespace CPP2
{
    std::string Merchant::Message() const
    {
        return Name;
    }
    
    std::string Merchant::Information() const
    {
        return Name + ":" + "\n" +
               "    Shop: " + Shop + "\n" +
               "    Description: " + Description + "\n" +
               "    Phrase: " + Phrase + "\n" +
               "    Money: " + std::to_string(Money);
    }
}