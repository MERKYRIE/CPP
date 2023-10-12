#include "Attribute.hpp"

namespace CPP
{
    std::string _Attribute::Message() const
    {
        return Title;
    }
    
    std::string _Attribute::Information() const
    {
        return Title + ": " + std::to_string(Value);
    }
}