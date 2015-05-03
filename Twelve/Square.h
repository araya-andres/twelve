#ifndef __Twelve__Square__
#define __Twelve__Square__

#include <stdio.h>
#include <Gosu/Gosu.hpp>


class Square
{
public:
    enum Color { red, green, blue };
    static const int SIDE = 100;

    Square(Gosu::Window&, Gosu::Font&, int column, int row, Color);
    void draw();
    void clear();
    void set(Color color, int number);
    
    int number() const { return _number; }
    Color color() const { return _color; }
    int column() const { return _col; }
    int row() const { return _row; }
    
private:
    static const int BORDER = 2;
    
    Gosu::Window& _window;
    Gosu::Font& _font;
    int _col;
    int _row;
    Color _color;
    int _number;
};

#endif /* defined(__Twelve__Square__) */
