#include <stdint.h>
#include <iostream>
#include "rectangle.h"

using namespace std;

Rectangle::Rectangle(){
    clog << "Default Constructor called" << endl;
    this->length = 5;
    this->width = 5;
}

/*Rectangle::Rectangle (uint32_t w, uint32_t l){
    clog << "Custom Constructor called" << endl;
    this->length = w;
    this->width = l;
}*/

Rectangle::Rectangle (uint32_t w, uint32_t l):width(w),length(l){
    clog << "Custom Constructor called" << endl;
}

void Rectangle::setWidth(uint32_t width){
    this->width = width; //object of this class
}

void Rectangle::setLength(uint32_t length){
    this->length = length;
}
