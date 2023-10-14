#include "Locations.hpp"

#include "Stores.hpp"
#include "Weaponries.hpp"

namespace CPP::Locations
{
    void Initialize()
    {
        Array[Type::Test].Title = "Test";
        Array[Type::Test].Transitions = {};
        Array[Type::Test].Stores = {&Stores::Array[Stores::Type::Test] , &Weaponries::Array[Weaponries::Type::Test]};
    }
}