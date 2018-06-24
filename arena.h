#ifndef AREANA_H
#define AREANA_H

#include <iostream>

class Arena {
    public:
        Arena(){}
        Arena(actor* x, actor* y):Arena(),a(x), b(y){}

        actor* getA();
        actor* getB();
    private:
        actor* a;
        actor* b;
}

#endif