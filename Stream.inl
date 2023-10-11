#pragma once

#include "Stream.hpp"

namespace CPP
{
    template<typename Type> std::ostream& operator<<(std::ostream& Stream , const std::vector<Type>& Vector)
    {
        std::string String;
        for(const Type& Value : Vector)
        {
            String += Value.Message();
        }
        Stream << String;
        return Stream;
    }
}