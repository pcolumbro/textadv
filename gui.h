#ifndef GUI_H
#define GUI_H

#include <iostream>
#include <string>

using namespace std;

class Gui{
    public:
        Gui(){};
        
        void waitForInput();

        // getters

        string getLastInput();


        // display commands

        void clearScreen();
        void displayActorStats(Actor* a);

        void displayText(string* arr, int n){
            for(int i = 0; i < n; i++)
                cout << arr[i] << endl;
        }

    private:
        string lastInput;
};

void Gui::displayActorStats(Actor* a){
    cout << "---------------------------" << endl;
    cout << "  Player Name  : " << a->name << endl;
    cout << "  health       : " << a->getHp() << endl;
    cout << "---------------------------" << endl;
    cout << "  dexterity    : " << a->dex << endl;
    cout << "  perception   : " << a->per << endl;
    cout << "  strength     : " << a->str << endl;
    cout << "  endurance    : " << a->end << endl;
    cout << "  agility      : " << a->agi << endl;
    cout << "  charisma     : " << a->cha << endl;
    cout << "  luck         : " << a->lck << endl;
    cout << "  spirit       : " << a->spr << endl;
    cout << "  intellect    : " << a->itl << endl;
    cout << "---------------------------" << endl;
}

string Gui::getLastInput(){
    return this->lastInput;
}

void Gui::clearScreen(){
    for(int i = 0; i<21; i++)
        std::cout << endl;
}

#endif