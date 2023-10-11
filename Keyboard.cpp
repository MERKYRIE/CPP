#include "Keyboard.hpp"

namespace CPP
{
    _Keyboard::_Keyboard() :
        _Last(256) ,
        _State(256)
    {
        
    }

    void _Keyboard::Update()
    {
        _Last = _State;
        GetKeyState(0);
        GetKeyboardState(_State.data());
    }
        
    bool _Keyboard::Pressed(std::uint8_t _Key)
    {
        return !(_Last[_Key] & 0x80) && (_State[_Key] & 0x80);
    }
}