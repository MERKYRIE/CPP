#include "Item.hpp"

namespace CPP
{
    class String Item::Message() const
    {
        return Title + ":" + "\n" +
               "                            Cost: " + std::to_string(Cost);
    }
}