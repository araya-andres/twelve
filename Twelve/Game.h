#ifndef __Twelve__Game__
#define __Twelve__Game__

#include <stdio.h>
#include <vector>
#include <Gosu/Gosu.hpp>

#include "Square.h"

class Game
{
public:
    Game(Gosu::Graphics&, Gosu::Font&);
    void draw() const;
    void restart();
    void handle_mouse_down(double x, double y);
    void handle_mouse_up(double x, double y);
    
private:
    Square* _start_square = nullptr;
    Square* _end_square = nullptr;
    std::vector<Square::Color> _color_list;
    std::vector<Square> _squares;
    
    void move(Square&, Square&);
    std::vector<Square*> squares_between_in_row(const Square&, const Square&);
    std::vector<Square*> squares_between_in_column(const Square&, const Square&);
};

#endif /* defined(__Twelve__Game__) */
