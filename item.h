#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item{
    public:
        Item(){};
        Item(string n, string d, int l)
            :name(n), description(d), level(i)
        {

        }

    private:
        string name;
        string description;
        int level;
}

enum WEAPON_TYPE : string {
    BLUNT,
    SLASH,
    PIERCE,
    UNARMED
}

#endif