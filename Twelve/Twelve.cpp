#include "Board.h"
#include "Twelve.h"

Twelve::Twelve()
    : Gosu::Window(Board::ROWS * Square::SIDE + 2 * Board::BORDER, Board::COLS * Square::SIDE + 2 * Board::BORDER, false)
    , _font(this->graphics(), L"System", 72)
    , _game(this->graphics(), _font)
{
    setCaption(L"Twelve");
}

void Twelve::draw()
{
    _game.draw();
}

bool Twelve::needsCursor() const
{
    return true;
}

void Twelve::buttonDown(Gosu::Button button)
{
    if (button.id() == Gosu::msLeft) {
        _game.handle_mouse_down(input().mouseX(), input().mouseY());
    }
}

void Twelve::buttonUp(Gosu::Button button)
{
    switch (button.id()) {
        case Gosu::msLeft:
            _game.handle_mouse_up(input().mouseX(), input().mouseY());
            break;
        case Gosu::kbR:
            _game.restart();
            break;
        default:
            // do nothing
            break;
    }
}
