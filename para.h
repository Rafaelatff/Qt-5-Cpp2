#ifndef PARA_H
#define PARA_H
#include <iostream>
#include <stdint.h>
#include "rectangle.h"

using namespace std;

/*************  Members of para class ************/
class Para{
public:
    Para(uint32_t w,uint32_t l, uint32_t h):r(w,l),height(h){
        cout << "Para Constructor Called" << endl;
    }
    uint32_t getVolume(){
        return r.getArea() * height;
    }
private:
    Rectangle r;
    uint32_t height;
};

#endif // PARA_H
