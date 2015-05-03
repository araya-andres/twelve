#include <Gosu/Gosu.hpp>
#include "Game.h"
#include "Square.h"

class Twelve : public Gosu::Window
{
public:
    static const int TOP_MARGIN = 20;
    static const int LEFT_MARGIN = 20;
    
    Twelve()
        : Gosu::Window(640, 640, false)
        , _font(this->graphics(), L"System", 72)
        , _game(*this, _font)
    {
        setCaption(L"Twelve");
    }
    
    virtual void draw() override
    {
        _game.draw();
    }
    
    virtual bool needsCursor() const override
    {
        return true;
    }
    
    virtual void buttonDown(Gosu::Button button) override
    {
        if (button.id() == Gosu::msLeft)
        {
            _game.handle_mouse_down(input().mouseX(), input().mouseY());
        }
    }
    
    virtual void buttonUp(Gosu::Button button) override
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
    
private:
    Gosu::Font _font;
    Game _game;
};

int main()
{
    Twelve window;
    window.show();
}