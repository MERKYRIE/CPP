#include "Location.hpp"

#include "Manipulator.hpp"
#include "String.hpp"

namespace CPP
{
    std::string Location::Message() const
    {
        return Title + ":" + "\n" +
               "            Merchants: " + "\n" +
               Spacing(Merchants , false , 16);
    }
}