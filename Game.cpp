#include "Game.hpp"

#include "Attribute.hpp"
#include "Bonus.hpp"
#include "Console.hpp"
#include "Damage.hpp"
#include "Damages.hpp"
#include "Item.hpp"
#include "Items.hpp"
#include "Keyboard.hpp"
#include "Location.hpp"
#include "Locations.hpp"
#include "Store.hpp"
#include "Stores.hpp"
#include "Weapon.hpp"
#include "Weaponries.hpp"
#include "Weaponry.hpp"
#include "Weapons.hpp"

namespace CPP::Game
{
    std::vector<_Location*> Locations;
    std::string Name;
    unsigned long long int Location;
    unsigned long long int Money;
    std::vector<_Item*> Inventory;
    _Weapon* Weapon;
    
    void Initialize()
    {
        Items::Initialize();
        Stores::Initialize();
        Damages::Initialize();
        Weapons::Initialize();
        Weaponries::Initialize();
        Locations::Initialize();
        Locations.push_back(&Locations::Array[Locations::Type::Test]);
        Name = "<Name>";
        Location = 0;
        Money = 1;
        Inventory = {};
        Weapon = &Weapons::Array[Weapons::Type::AntlerAxe];
    }

    void Inspect()
    {
        std::cout << Name << ":" << "\n"
                  << "    Location: " << Console.Information(Locations[Location] , 4 , false)
                  << "    Money: " << Money << "\n"
                  << "    Inventory: " << "\n"
                  << Console.Information(Inventory , 8 , true)
                  << "    Weapon: " << Console.Information(Weapon , 4 , false) << "\n\n";
    }

    void Buy()
    {
        std::vector<std::string> Entries;
        for(const _Store* Store : Locations[Location]->Stores)
        {
            Entries.push_back(Store->Information());
        }
        if(Entries.empty())
        {
            std::cout << "Nobody to buy something from!" << "\n\n";
            return;
        }
        unsigned long long int Store{Console.Menu(Entries) - 1};
        if(Store == std::numeric_limits<unsigned long long int>::max())
        {
            return;
        }
        if(Locations[Location]->Stores[Store]->Inventory.empty())
        {
            std::cout << Locations[Location]->Stores[Store]->Title << ": 'There's no goods for you!'" << "\n\n";
            return;
        }
        Entries.clear();
        for(const _Item* Item : Locations[Location]->Stores[Store]->Inventory)
        {
            Entries.push_back(Item->Information());
        }
        unsigned long long int Item{Console.Menu(Entries) - 1};
        if(Item == std::numeric_limits<unsigned long long int>::max())
        {
            return;
        }
        if(Money >= Locations[Location]->Stores[Store]->Inventory[Item]->Cost)
        {
            Money -= Locations[Location]->Stores[Store]->Inventory[Item]->Cost;
            Inventory.push_back(Locations[Location]->Stores[Store]->Inventory[Item]);
            Locations[Location]->Stores[Store]->Inventory.erase(Locations[Location]->Stores[Store]->Inventory.begin() + Item);
            std::cout << Locations[Location]->Stores[Store]->Title << ": 'Sold!'" << "\n\n";
            return;
        }
        std::cout << Locations[Location]->Stores[Store]->Title << ": 'It's to expensive for you!'" << "\n\n";
    }

    void Sell()
    {
        std::vector<std::string> Entries;
        for(const _Store* Store : Locations[Location]->Stores)
        {
            Entries.push_back(Store->Information());
        }
        if(Entries.empty())
        {
            std::cout << "Nobody to sell something to!" << "\n\n";
            return;
        }
        unsigned long long int Store{Console.Menu(Entries) - 1};
        if(Store == std::numeric_limits<unsigned long long int>::max())
        {
            return;
        }
        if(Inventory.empty())
        {
            std::cout << Locations[Location]->Stores[Store]->Title << ": 'You've no goods for me!'" << "\n\n";
            return;
        }
        Entries.clear();
        for(const _Item* Item : Inventory)
        {
            Entries.push_back(Item->Information());
        }
        unsigned long long int Item{Console.Menu(Entries) - 1};
        if(Item == std::numeric_limits<unsigned long long int>::max())
        {
            return;
        }
        if(Locations[Location]->Stores[Store]->Money >= Inventory[Item]->Cost)
        {
            Locations[Location]->Stores[Store]->Money -= Inventory[Item]->Cost;
            Locations[Location]->Stores[Store]->Inventory.push_back(Inventory[Item]);
            Inventory.erase(Inventory.begin() + Item);
            std::cout << Locations[Location]->Stores[Store]->Title << ": 'Bought!'" << "\n\n";
            return;
        }
        std::cout << Locations[Location]->Stores[Store]->Title << ": 'It's to expensive for me!'" << "\n\n";
    }

    void Attack()
    {
        std::vector<std::string> Entries;
        for(const _Store* Store : Locations[Location]->Stores)
        {
            Entries.push_back(Store->Information());
        }
        if(Entries.empty())
        {
            std::cout << "Nobody to attack!" << "\n\n";
            return;
        }
        unsigned long long int Store{Console.Menu(Entries) - 1};
        if(Store == std::numeric_limits<unsigned long long int>::max())
        {
            return;
        }
        if(Locations[Location]->Stores[Store]->Dead)
        {
            std::cout << "He's dead already!" << "\n\n";
            return;
        }
        Locations[Location]->Stores[Store]->Dead = true;
        std::cout << "You killed the local merchant." << "\n"
                  << "Now the whole town is againt you." << "\n"
                  << "You are hunted by the town peasants." << "\n\n";
    }

    void Loot()
    {
        std::vector<std::string> Entries;
        for(const _Store* Store : Locations[Location]->Stores)
        {
            Entries.push_back(Store->Information());
        }
        if(Entries.empty())
        {
            std::cout << "Nobody to loot!" << "\n\n";
            return;
        }
        unsigned long long int Store{Console.Menu(Entries) - 1};
        if(Store == std::numeric_limits<unsigned long long int>::max())
        {
            return;
        }
        if(!Locations[Location]->Stores[Store]->Dead)
        {
            std::cout << Locations[Location]->Stores[Store]->Title << ": 'What are you doing here!'" << "\n\n";
            return;
        }
        if(Locations[Location]->Stores[Store]->Inventory.empty())
        {
            std::cout << "He's looted already!" << "\n\n";
            return;
        }
        std::cout << "You were murdered by the town peasants." << "\n\n";
        Console.Pause();
        std::exit(0);
    }

    void Travel()
    {
        std::vector<std::string> Entries;
        std::vector<unsigned long long int> Options;
        for(unsigned long long int Transition{0} ; Transition < Locations[Location]->Transitions.size() ; Transition++)
        {
            Entries.push_back(Locations[Locations[Location]->Transitions[Transition]]->Message());
            Options.push_back(Transition + 1);
        }
        if(Entries.empty())
        {
            std::cout << "Nowhere to travel!" << "\n\n";
            return;
        }
        unsigned long long int Transition{Console.Menu(Entries , Options)};
        if(Transition == std::numeric_limits<unsigned long long int>::min())
        {
            return;
        }
        Location = Locations[Location]->Transitions[Transition - 1];
    }

    void Speak()
    {
    
    }
}

signed int main()
{
    ::CPP::Game::Initialize();
    do
    {
        switch(::CPP::Console.Menu
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
                ::CPP::Game::Inspect();
            break;
            case 2:
                ::CPP::Game::Buy();
            break;
            case 3:
                ::CPP::Game::Sell();
            break;
            case 4:
                ::CPP::Game::Attack();
            break;
            case 5:
                ::CPP::Game::Loot();
            break;
            case 6:
                ::CPP::Game::Travel();
            break;
            case 7:
                ::CPP::Game::Speak();
            break;
        }
    }
    while(true);
}