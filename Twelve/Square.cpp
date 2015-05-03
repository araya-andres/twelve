#include <sstream>
#include "Game.h"
#include "Square.h"

Square::Square(Gosu::Graphics& graphics, Gosu::Font& font, int column, int row, Color color)
    : _graphics(graphics)
    , _font(font)
    , _col(column)
    , _row(row)
    , _color(color)
{
    _number = 1;
}

void Square::draw()
{
    static Gosu::Color colors[] = {
        Gosu::Color(0xaa, 0xff, 0x00, 0x00),
        Gosu::Color(0xaa, 0x00, 0xff, 0x00),
        Gosu::Color(0xaa, 0x00, 0x00, 0xff)
    };
    
    if (_number == 0) return;
    
    // draw square
    double x1 = Game::BORDER + BORDER + _col * SIDE;
    double y1 = Game::BORDER + BORDER + _row * SIDE;
    double x2 = x1 + SIDE - 2 * BORDER;
    double y2 = y1;
    double x3 = x2;
    double y3 = y2 + SIDE - 2 * BORDER;
    double x4 = x1;
    double y4 = y3;
    Gosu::Color& c = colors[_color];
    _graphics.drawQuad(x1, y1, c, x2, y2, c, x3, y3, c, x4, y4, c, 1);
    
    // draw text
    std::wostringstream oss;
    oss << _number;
    double x_center = x1 + SIDE / 2 - BORDER;
    double x_text = x_center - _font.textWidth(oss.str()) / 2;
    double y_text = y1 + 12;
    _font.draw(oss.str(), x_text, y_text, 0);
}

void Square::clear()
{
    _number = 0;
}

void Square::set(Color color, int number)
{
    _color = color;
    _number = number;
}