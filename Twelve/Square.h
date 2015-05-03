//
//  Square.h
//  Twelve
//
//  Created by Andres Araya Rojas on 5/2/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

#ifndef __Twelve__Square__
#define __Twelve__Square__

#include <stdio.h>
#include <Gosu/Gosu.hpp>


class Square
{
public:
    enum Color { red, green, blue };

    Square(Gosu::Window&, Gosu::Font&, int column, int row, Color);
    void draw();
    void clear();
    void set(Color color, int number);
    
private:
    Gosu::Window& _window;
    Gosu::Font& _font;
    int _col;
    int _row;
    Color _color;
    int _number;
};

#endif /* defined(__Twelve__Square__) */
