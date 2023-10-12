#include "Bonus.hpp"

namespace CPP
{
    std::string _Bonus::Message() const
    {
        return Attribute.Message();
    }
    
    std::string _Bonus::Information() const
    {
        return Attribute.Information();
    }
}