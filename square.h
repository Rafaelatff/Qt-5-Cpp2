#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include <stdint.h>
#include "rectangle.h"

using namespace std;

/*************  Members of Square class ************/
// Here we will have a class that extends the rectangle and inherit everything from
// the public space of rectangle class
class Square: public Rectangle{
public:
    Square(uint32_t side):Rectangle(side,side){
    }
 };

#endif // SQUARE_H
