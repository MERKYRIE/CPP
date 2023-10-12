#include "Game.hpp"

#include "Console.hpp"
#include "Keyboard.hpp"

namespace CPP2
{
    Game::Game()
    {
        Locations.emplace_back();
        Locations.back().Title = "Location 0";
        Locations.back().Transitions = {1};
        Locations.back().Merchants.emplace_back();
        Locations.back().Merchants.back().Name = "Merchant 0";
        Locations.back().Merchants.back().Shop = "<Shop>";
        Locations.back().Merchants.back().Description = "<Description>";
        Locations.back().Merchants.back().Phrase = "<Phrase>";
        Locations.back().Merchants.back().Money = 0;
        Locations.back().Merchants.back().Inventory.emplace_back();
        Locations.back().Merchants.back().Inventory.back().Title = "Item 0";
        Locations.back().Merchants.back().Inventory.back().Cost = 0;
        Locations.back().Merchants.back().Inventory.emplace_back();
        Locations.back().Merchants.back().Inventory.back().Title = "Item 1";
        Locations.back().Merchants.back().Inventory.back().Cost = 1;
        Locations.back().Merchants.emplace_back();
        Locations.back().Merchants.back().Name = "Merchant 1";
        Locations.back().Merchants.back().Shop = "<Shop>";
        Locations.back().Merchants.back().Description = "<Description>";
        Locations.back().Merchants.back().Phrase = "<Phrase>";
        Locations.back().Merchants.back().Money = 0;
        Locations.back().Merchants.back().Inventory.emplace_back();
        Locations.back().Merchants.back().Inventory.back().Title = "Item 0";
        Locations.back().Merchants.back().Inventory.back().Cost = 0;
        Locations.back().Merchants.back().Inventory.emplace_back();
        Locations.back().Merchants.back().Inventory.back().Title = "Item 1";
        Locations.back().Merchants.back().Inventory.back().Cost = 1;
        Locations.emplace_back();
        Locations.back().Title = "Location 1";
        Locations.back().Transitions = {0 , 2};
        Locations.back().Merchants.emplace_back();
        Locations.back().Merchants.back().Name = "Merchant 0";
        Locations.back().Merchants.back().Shop = "<Shop>";
        Locations.back().Merchants.back().Description = "<Description>";
        Locations.back().Merchants.back().Phrase = "<Phrase>";
        Locations.back().Merchants.back().Money = 0;
        Locations.back().Merchants.back().Inventory.emplace_back();
        Locations.back().Merchants.back().Inventory.back().Title = "Item 0";
        Locations.back().Merchants.back().Inventory.back().Cost = 0;
        Locations.back().Merchants.back().Inventory.emplace_back();
        Locations.back().Merchants.back().Inventory.back().Title = "Item 1";
        Locations.back().Merchants.back().Inventory.back().Cost = 1;
        Locations.back().Merchants.emplace_back();
        Locations.back().Merchants.back().Name = "Merchant 1";
        Locations.back().Merchants.back().Shop = "<Shop>";
        Locations.back().Merchants.back().Description = "<Description>";
        Locations.back().Merchants.back().Phrase = "<Phrase>";
        Locations.back().Merchants.back().Money = 0;
        Locations.back().Merchants.back().Inventory.emplace_back();
        Locations.back().Merchants.back().Inventory.back().Title = "Item 0";
        Locations.back().Merchants.back().Inventory.back().Cost = 0;
        Locations.back().Merchants.back().Inventory.emplace_back();
        Locations.back().Merchants.back().Inventory.back().Title = "Item 1";
        Locations.back().Merchants.back().Inventory.back().Cost = 1;
        Locations.emplace_back();
        Locations.back().Title = "Location 2";
        Locations.back().Transitions = {1};
        Locations.back().Merchants.emplace_back();
        Locations.back().Merchants.back().Name = "Merchant 0";
        Locations.back().Merchants.back().Shop = "<Shop>";
        Locations.back().Merchants.back().Description = "<Description>";
        Locations.back().Merchants.back().Phrase = "<Phrase>";
        Locations.back().Merchants.back().Money = 0;
        Locations.back().Merchants.back().Inventory.emplace_back();
        Locations.back().Merchants.back().Inventory.back().Title = "Item 0";
        Locations.back().Merchants.back().Inventory.back().Cost = 0;
        Locations.back().Merchants.back().Inventory.emplace_back();
        Locations.back().Merchants.back().Inventory.back().Title = "Item 1";
        Locations.back().Merchants.back().Inventory.back().Cost = 1;
        Locations.back().Merchants.emplace_back();
        Locations.back().Merchants.back().Name = "Merchant 1";
        Locations.back().Merchants.back().Shop = "<Shop>";
        Locations.back().Merchants.back().Description = "<Description>";
        Locations.back().Merchants.back().Phrase = "<Phrase>";
        Locations.back().Merchants.back().Money = 0;
        Locations.back().Merchants.back().Inventory.emplace_back();
        Locations.back().Merchants.back().Inventory.back().Title = "Item 0";
        Locations.back().Merchants.back().Inventory.back().Cost = 0;
        Locations.back().Merchants.back().Inventory.emplace_back();
        Locations.back().Merchants.back().Inventory.back().Title = "Item 1";
        Locations.back().Merchants.back().Inventory.back().Cost = 1;
        Name = "<Name>";
        Location = 0;
        Money = 1;
        Inventory = {};
        Weapon.Title = "<Weapon>";
    }

    void Game::Inspect()
    {
        std::cout << Name << ":" << "\n"
                  << "    Location: " << Locations[Location].Title << "\n"
                  << "    Money: " << Money << "\n"
                  << "    Inventory: " << "\n"
                  << (Inventory.empty() ? "" : Console.Information(Inventory , 8 , true) + "\n")
                  << "    Weapon: " << Console.Information(Weapon , 4 , false) << "\n\n";
    }

    void Game::Buy()
    {
        std::vector<std::string> Entries;
        for(const class Merchant& Merchant : Locations[Location].Merchants)
        {
            Entries.push_back(Merchant.Information());
        }
        if(Entries.empty())
        {
            std::cout << "Nobody to buy something from!" << "\n\n";
            return;
        }
        unsigned long long int Merchant{Console.Menu(Entries) - 1};
        if(Locations[Location].Merchants[Merchant].Inventory.empty())
        {
            std::cout << Locations[Location].Merchants[Merchant].Name << ": 'There's no goods for you!'" << "\n\n";
            return;
        }
        Entries.clear();
        for(const class Item& Item : Locations[Location].Merchants[Merchant].Inventory)
        {
            Entries.push_back(Item.Information());
        }
        unsigned long long int Item{Console.Menu(Entries) - 1};
        if(Money >= Locations[Location].Merchants[Merchant].Inventory[Item].Cost)
        {
            Money -= Locations[Location].Merchants[Merchant].Inventory[Item].Cost;
            Inventory.push_back(Locations[Location].Merchants[Merchant].Inventory[Item]);
            Locations[Location].Merchants[Merchant].Inventory.erase(Locations[Location].Merchants[Merchant].Inventory.begin() + Item);
            std::cout << Locations[Location].Merchants[Merchant].Name << ": 'Sold!'" << "\n\n";
        }
        std::cout << Locations[Location].Merchants[Merchant].Name << ": 'It's to expensive for you!'" << "\n\n";
    }

    void Game::Sell()
    {
        std::vector<std::string> Entries;
        for(const class Merchant& Merchant : Locations[Location].Merchants)
        {
            Entries.push_back(Merchant.Information());
        }
        if(Entries.empty())
        {
            std::cout << "Nobody to sell something to!" << "\n\n";
            return;
        }
        unsigned long long int Merchant{Console.Menu(Entries) - 1};
        if(Inventory.empty())
        {
            std::cout << Locations[Location].Merchants[Merchant].Name << ": 'You've no goods for me!'" << "\n\n";
            return;
        }
        Entries.clear();
        for(const class Item& Item : Inventory)
        {
            Entries.push_back(Item.Information());
        }
        unsigned long long int Item{Console.Menu(Entries) - 1};
        if(Locations[Location].Merchants[Merchant].Money >= Inventory[Item].Cost)
        {
            Locations[Location].Merchants[Merchant].Money -= Inventory[Item].Cost;
            Locations[Location].Merchants[Merchant].Inventory.push_back(Inventory[Item]);
            Inventory.erase(Inventory.begin() + Item);
            std::cout << Locations[Location].Merchants[Merchant].Name << ": 'Bought!'" << "\n\n";
        }
        std::cout << Locations[Location].Merchants[Merchant].Name << ": 'It's to expensive for me!'" << "\n\n";
    }

    void Game::Attack()
    {
        std::vector<std::string> Entries;
        for(const class Merchant& Merchant : Locations[Location].Merchants)
        {
            Entries.push_back(Merchant.Information());
        }
        if(Entries.empty())
        {
            std::cout << "Nobody to attack!" << "\n\n";
            return;
        }
        unsigned long long int Merchant{Console.Menu(Entries) - 1};
        if(Locations[Location].Merchants[Merchant].Dead)
        {
            std::cout << "He's dead already!" << "\n\n";
        }
        Locations[Location].Merchants[Merchant].Dead = true;
        std::cout << "You killed the local merchant." << "\n"
                  << "Now the whole town is againt you." << "\n"
                  << "You are hunted by the town peasants." << "\n\n";
    }

    void Game::Loot()
    {
        std::vector<std::string> Entries;
        for(const class Merchant& Merchant : Locations[Location].Merchants)
        {
            Entries.push_back(Merchant.Information());
        }
        if(Entries.empty())
        {
            std::cout << "Nobody to loot!" << "\n\n";
            return;
        }
        unsigned long long int Merchant{Console.Menu(Entries) - 1};
        if(!Locations[Location].Merchants[Merchant].Dead)
        {
            std::cout << Locations[Location].Merchants[Merchant].Name << ": 'What are you doing here!'" << "\n\n";
            return;
        }
        if(Locations[Location].Merchants[Merchant].Inventory.empty())
        {
            std::cout << "He's looted already!" << "\n\n";
            return;
        }
        std::cout << "You were murdered by the town peasants." << "\n\n";
        Console.Pause();
        std::exit(0);
    }

    void Game::Travel()
    {
        std::vector<std::string> Entries;
        std::vector<unsigned long long int> Options;
        for(unsigned long long int Transition{0} ; Transition < Locations[Location].Transitions.size() ; Transition++)
        {
            Entries.push_back(Locations[Locations[Location].Transitions[Transition]].Information());
            Options.push_back(Transition);
        }
        if(Entries.empty())
        {
            std::cout << "Nowhere to travel!" << "\n\n";
            return;
        }
        unsigned long long int Transition{Console.Menu(Entries , Options)};
        this->Location = Locations[Location].Transitions[Transition];
    }

    void Game::Speak()
    {
    
    }
}

signed int main()
{
    do
    {
        switch(::CPP2::Console.Menu
        ({
            "Inspect" ,
            "Buy" ,
            "Sell" ,
            "Attack" ,
            "Loot" ,
            "Travel" ,
            "Speak"
        }))
        {
            case 0:
                return 0;
            break;
            case 1:
                ::CPP2::Game.Inspect();
            break;
            case 2:
                ::CPP2::Game.Buy();
            break;
            case 3:
                ::CPP2::Game.Sell();
            break;
            case 4:
                ::CPP2::Game.Attack();
            break;
            case 5:
                ::CPP2::Game.Loot();
            break;
            case 6:
                ::CPP2::Game.Travel();
            break;
            case 7:
                ::CPP2::Game.Speak();
            break;
        }
    }
    while(true);
}