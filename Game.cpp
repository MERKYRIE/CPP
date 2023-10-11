#include "Game.hpp"

#include "Console.hpp"
#include "Keyboard.hpp"
#include "Manipulator.hpp"
#include "Stream.hpp"
#include "String.hpp"

namespace CPP
{
    Game::Game()
    {
        Locations.emplace_back();
        Locations.back().Title = "Location 0";
        Locations.back().Merchants.emplace_back();
        Locations.back().Merchants.back().Name = "Merchant 0";
        Locations.back().Merchants.back().Shop = "Old Goblin and his sons";
        Locations.back().Merchants.back().Description = "Steals and sells";
        Locations.back().Merchants.back().Phrase = "That can't be any cheaper";
        Locations.back().Merchants.back().Money = 1'000'000;
        Locations.back().Merchants.back().Inventory.emplace_back();
        Locations.back().Merchants.back().Inventory.back().Title = "Staff";
        Locations.back().Merchants.back().Inventory.back().Cost = 900;
        Locations.back().Merchants.emplace_back();
        Locations.back().Merchants.back().Name = "Merchant 1";
        Locations.back().Merchants.back().Shop = "Old Goblin and his sons";
        Locations.back().Merchants.back().Description = "Steals and sells";
        Locations.back().Merchants.back().Phrase = "That can't be any cheaper";
        Locations.back().Merchants.back().Money = 1'000'000;
        Locations.back().Merchants.back().Inventory.emplace_back();
        Locations.back().Merchants.back().Inventory.back().Title = "Staff";
        Locations.back().Merchants.back().Inventory.back().Cost = 900;
        Locations.emplace_back();
        Locations.back().Title = "Location 1";
        Locations.back().Merchants.emplace_back();
        Locations.back().Merchants.back().Name = "Merchant 0";
        Locations.back().Merchants.back().Shop = "Old Goblin and his sons";
        Locations.back().Merchants.back().Description = "Steals and sells";
        Locations.back().Merchants.back().Phrase = "That can't be any cheaper";
        Locations.back().Merchants.back().Money = 1'000'000;
        Locations.back().Merchants.back().Inventory.emplace_back();
        Locations.back().Merchants.back().Inventory.back().Title = "Staff";
        Locations.back().Merchants.back().Inventory.back().Cost = 900;
        Locations.back().Merchants.emplace_back();
        Locations.back().Merchants.back().Name = "Merchant 1";
        Locations.back().Merchants.back().Shop = "Old Goblin and his sons";
        Locations.back().Merchants.back().Description = "Steals and sells";
        Locations.back().Merchants.back().Phrase = "That can't be any cheaper";
        Locations.back().Merchants.back().Money = 1'000'000;
        Locations.back().Merchants.back().Inventory.emplace_back();
        Locations.back().Merchants.back().Inventory.back().Title = "Staff";
        Locations.back().Merchants.back().Inventory.back().Cost = 900;
        Location = 0;
        Name = "Nameless One";
        Money = 1000;
        Inventory = {};
        Information();
    }

    void Game::Information()
    {
        String String{"1\n2\n3\n"};
        std::cout << String.Information(4) << "\n\n";
        std::cout << "Game:" << "\n"
                  << "    Locations: " << "\n"
                  << Spacing(Locations , false , 8) << "\n"
                  << "    Location: " << Locations[Location].Title << "\n"
                  << "    Name: " << Name << "\n"
                  << "    Money: " << Money << "\n"
                  << "    Inventory: " << "\n"
                  << Spacing(Inventory , false , 8) << "\n";
    }

    void Game::Buy()
    {
        std::vector<class String> Entries;
        for(const class Merchant& Merchant : Locations[Location].Merchants)
        {
            Entries.push_back(Merchant.Message());
        }
        unsigned long long int Merchant{Console.Menu(Entries) - 1};
        Entries.clear();
        for(const class Item& Item : Locations[Location].Merchants[Merchant].Inventory)
        {
            Entries.push_back(Item.Message());
        }
        unsigned long long int Item{Console.Menu(Entries) - 1};
        if(Money >= Locations[Location].Merchants[Merchant].Inventory[Item].Cost)
        {
            Money -= Locations[Location].Merchants[Merchant].Inventory[Item].Cost;
            Inventory.push_back(Locations[Location].Merchants[Merchant].Inventory[Item]);
            Locations[Location].Merchants[Merchant].Inventory.erase(Locations[Location].Merchants[Merchant].Inventory.begin() + Item);
        }
    }

    void Game::Sell()
    {
        
    }

    void Game::Attack()
    {
        //Merchant.Defend();
    }

    void Game::Loot()
    {
        //Merchant.Looted();
    }
}

signed int main()
{
    do
    {
        switch(::CPP::Console.Menu
        ({
            "Information" ,
            "Buy" ,
            "Sell" ,
            "Attack" ,
            "Loot"
        }))
        {
            case 0:
                return 0;
            break;
            case 1:
                ::CPP::Game.Information();
            break;
            case 2:
                ::CPP::Game.Buy();
            break;
            case 3:
                ::CPP::Game.Sell();
            break;
            case 4:
                ::CPP::Game.Attack();
            break;
            case 5:
                ::CPP::Game.Loot();
            break;
        }
    }
    while(true);
}