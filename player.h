#ifndef PLAYER_H
#define PLAYER_H

#define BASE_PLAYER_STAT 10

using namespace std;

class Actor {

    public:

        Actor()
            : hp(100), dex(BASE_PLAYER_STAT), per(BASE_PLAYER_STAT), str(BASE_PLAYER_STAT), end(BASE_PLAYER_STAT), agi(BASE_PLAYER_STAT), cha(BASE_PLAYER_STAT), lck(BASE_PLAYER_STAT), spr(BASE_PLAYER_STAT), itl(BASE_PLAYER_STAT)
        {
            this->hp = 100;
            cout << "Actor " << this->name << " created!" << endl;
        }

        Actor(string n)
            : Actor::Actor()
        {
            this->name=n;
        }
       
        int getHp();
        int takeDamage(int val);
        int heal(int val);
        bool isAlive();
        
        int dex;
        int per;
        int str;
        int end;
        int agi;
        int cha;
        int lck;
        int spr;
        int itl;

        string name;

    private:
        int hp;


};

bool Actor::isAlive(){
    return (this->hp>0);
}

int Actor::getHp(){
    return this->hp;
}

int Actor::takeDamage(int val){
    return this->hp -= val;
}

int Actor::heal(int val){
    return this->hp += val;
}

class Player : public Actor {
    public:
        Player(){}
        Player(string n)
            : Actor(n)
        {
 
        }
};

#endif



