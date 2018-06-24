#ifndef GAME_H
#define GAME_H

#define arraysize(ar) ( sizeof(ar) / sizeof(ar[0]) )

#include <iostream>
#include "player.h"
#include "gui.h"

using namespace std;

class Game {

    public:
        Game(){
            this->actorCounter = 1;
            this->turnCounter = 1;
            this->gameLength = 20;
            this->mobs = new Actor[100];
        };

        Game(string n)
            : Game()
        {
            this->player = new Player(n);
        }   


        Player* getPlayer();

        Actor* addRandomMonster();
        
        void run();

        void advanceTurn();
        void runPlayerTurn();
        void runNpcTurn();

        bool runCheck(int val);
        bool runCheck(int max, int val);

    private:
        Actor* mobs;
        Player* player;
        int turnCounter;
        int actorCounter;
        int gameLength;

};

void Game::run(){
    cout << "-------------------------------" << endl;
    cout << "      Starting your adventure!" << endl;
    cout << "-------------------------------" << endl;
    for(int i = 0; i < this->gameLength; i++){
        cout << "---- start turn no. " << i+1 << " ----" << endl;
        this->advanceTurn();
        cout << "-------- end turn ---------" << endl;

    }
    cout << "-------------------------------" << endl;
    cout << "           Game over!" << endl;
    cout << "-------------------------------" << endl;
}

Player* Game::getPlayer(){
    return this->player;
}

bool Game::runCheck(int val){
    return ((rand() % 101) > val) ? true : false;
}

bool Game::runCheck(int max, int val){
    return ((rand() % (max + 1) > val)) ? true : false;
}

void Game::advanceTurn(){
    this->runPlayerTurn();
    this->runNpcTurn();
    this->turnCounter++;
}

void Game::runPlayerTurn(){
    cout << "Player [" << this->player->getHp() << " hp] turn no. " << this->turnCounter << "! :D" << endl;
}

void Game::runNpcTurn(){
    cout << "Npc turn no. "  << this->turnCounter << "! D:" << endl;
}


Actor* Game::addRandomMonster(){
    string name[] = {"angry", "strong", "scary", "sad", "mad", "crazy", "fierce"};
    
    Actor* a = new Actor();

    a->dex = rand() % 10 + 1;
    a->per = rand() % 10 + 1;
    a->str = rand() % 10 + 1;
    a->end = rand() % 10 + 1;
    a->agi = rand() % 10 + 1;
    a->cha = rand() % 10 + 1;
    a->lck = rand() % 10 + 1;
    a->spr = rand() % 10 + 1;
    a->itl = rand() % 10 + 1;

    a->name = name[(rand() % arraysize(name))] + " boi";

    this->mobs[arraysize(mobs)] = *a;
}

#endif