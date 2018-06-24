
#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "player.h"
#include "gui.h"

using namespace std;

class Game {

    public:
        Game(){
            this->player = new Player();
            this->actorCounter = 1;
            this->turnCounter = 1;
            this->gameLength = 20;
        };

        Game(string n){
            this->player = new Player(n);
            this->actorCounter = 1;
            this->turnCounter = 1;
            this->gameLength = 20;
        }   


        Player* getPlayer();
        
        void run();

        void advanceTurn();
        void runPlayerTurn();
        void runNpcTurn();

        bool runCheck(int val);
        bool runCheck(int max, int val);

    private:
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



#endif