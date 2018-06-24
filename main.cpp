#include <iostream>
#include "game.h"

using namespace std;

string _PLAYER_NAME = "Hero";

int main(int argc, char* argv[]){
    
    // program initialization
    clock_t _STIME = clock();
    srand(time(NULL));
    int _TIMES = 1000;

    if(argc == 3){
        _TIMES = atoi(argv[2]);
    }

    // set player name if given
    if(argc > 1){
        _PLAYER_NAME = argv[1];
    }

    Gui* gui = new Gui();
    Game* game = new Game(_PLAYER_NAME);

    gui->displayActorStats(game->getPlayer());

    int pass, fail;
    pass = 0, fail = 0;
    for(int i = 0; i < _TIMES; i++){
        if(game->runCheck(50)){
            pass++;
        }else{
            fail++;
        }
    }
    clock_t _ETIME = clock();

    cout << "elapse: " << (float)(_ETIME - _STIME)/CLOCKS_PER_SEC << endl;
    cout << "pass  : " << pass << endl;
    cout << "fail  : " << fail << endl;
    cout << "total : " << pass + fail << endl;
    cout << "  %   : " << (((float)pass/(pass + fail)) * 100) << endl;
}