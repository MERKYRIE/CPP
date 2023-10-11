#include "Merchant.hpp"

#include "Console.hpp"
#include "String.hpp"

namespace CPP
{
    class String Merchant::Message() const
    {
        return Name + ":" + "\n" +
               "    Shop: " + Shop + "\n" +
               "    Description: " + Description + "\n" +
               "    Phrase: " + Phrase + "\n" +
               "    Money: " + Money + "\n" +
               "    Inventory: " + "\n" +
               "        " + Inventory;
    }

    void Merchant::Defend()
    {
        /*
        switch(Dead)
        {
            case false:
                Dead = true;
                switch(Console.Menu
                ({
                    "Merchant"
                }))
                {
                    case 1:
                        std::cout << "You killed the local merchant." << "\n"
                                  << "Now the whole town is againt you." << "\n"
                                  << "You are hunted by the town peasants." << "\n\n";
                    break;
                }
            break;
            case true:
                std::cout << "Nobody to attack." << "\n\n";
            break;
        }
        */
    }

    void Merchant::Looted()
    {
        /*
        switch(Dead)
        {
            case false:
                std::cout << "Nobody to loot." << "\n\n";
            break;
            case true:
                switch(Console.Menu
                ({
                    "Merchant"
                }))
                {
                    case 1:
                        std::cout << "You were murdered by the town peasants." << "\n\n";
                        Console.Pause();
                        std::exit(0);
                    break;
                }
            break;
        }
        */
    }

    bool Merchant::Buy(unsigned long long int& Money)
    {
        /*
        std::vector<std::string> Entries;
        unsigned long long int Weapon;
        if(Inventory.empty())
        {
            for(const class Weapon& Weapon : Inventory)
            {
                Entries.push_back(Weapon.Message());
            }
            Weapon = Console.Menu(Entries);
            if(Inventory[Weapon].Bought(Money))
            {
                return false;
            }
            else
            {
                Inventory.erase(Inventory.begin() + Weapon);
                std::cout << Name << ": 'Bought!'" << "\n\n";
                return true;
            }
        }
        else
        {
            std::cout << "Nothing to sell." << "\n\n";
            return false;
        }
        */
        return false;
    }
}