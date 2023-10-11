#pragma once

#include <iostream>
#include <vector>

namespace CPP
{
    template<typename Type> std::ostream& operator<<(std::ostream& Stream , const std::vector<Type>& Vector);
}

#include "Stream.inl"