#include "Twelve.h"

Twelve::Twelve()
    : Gosu::Window(Game::ROWS * Square::SIDE + 2 * Game::BORDER, Game::COLS * Square::SIDE + 2 * Game::BORDER, false)
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
    if (button.id() == Gosu::msLeft)
    {
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
            // TODO: restart game
            break;
        default:
            // do nothing
            break;
    }
}
