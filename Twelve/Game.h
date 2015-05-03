//
//  Game.h
//  Twelve
//
//  Created by Andres Araya Rojas on 5/2/15.
//  Copyright (c) 2015 edu.self. All rights reserved.
//

#ifndef __Twelve__Game__
#define __Twelve__Game__

#include <stdio.h>
#include <vector>
#include <Gosu/Gosu.hpp>
#include "Square.h"

class Game
{
public:
    Game(Gosu::Window&, Gosu::Font&);
    void draw();
    void handle_mouse_down(double x, double y);
    void handle_mouse_up(double x, double y);
    
private:
    const int ROWS = 6;
    const int COLS = 6;
    
    Square& get_square(int row, int col);
    void move(Square&, Square&);
    std::vector<Square> squares_between_in_row(Square&, Square&);
    std::vector<Square> squares_between_in_column(Square&, Square&);
    std::vector<Square> _squares;
};

#endif /* defined(__Twelve__Game__) */
