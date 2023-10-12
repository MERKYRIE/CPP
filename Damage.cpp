#include "Damage.hpp"

namespace CPP
{
    std::string _Damage::Message() const
    {
        return std::to_string(Minimum) + "-" + std::to_string(Maximum);
    }
    
    std::string _Damage::Information() const
    {
        return "Minimum: " + std::to_string(Minimum) + "\n" +
               "Maximum: " + std::to_string(Maximum) + "\n" +
               "Type: " + Damages::Array[Type];
    }
}