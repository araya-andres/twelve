#include <Gosu/Gosu.hpp>
#include "square.h"

class Twelve : public Gosu::Window
{
public:
    Twelve()
        : Gosu::Window(640, 640, false)
        , _font(this->graphics(), L"System", 72)
    {
        setCaption(L"Twelve");
    }
    
    virtual void draw() override
    {
        Square square1(*this, _font, 0, 0, Square::Color::green);
        Square square2(*this, _font, 5, 5, Square::Color::blue);
        square1.draw();
        square2.draw();
    }
    
private:
    Gosu::Font _font;
};

int main()
{
    Twelve window;
    window.show();
}