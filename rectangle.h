#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
#include <stdint.h>

using namespace std;

/*************  Members of rectangle class ************/
class Rectangle{
public:
    // Constructor
    Rectangle(); // Default constructor
    Rectangle (uint32_t w, uint32_t l);

    // Methods
    void setWidth(uint32_t width);
    void setLength(uint32_t length);
    int getArea(){
        return width * length;
    }

private:
    uint32_t width;
    uint32_t length;
};

#endif // RECTANGLE_H
