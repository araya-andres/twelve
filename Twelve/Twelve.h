#ifndef __Twelve__Twelve__
#define __Twelve__Twelve__

#include <Gosu/Gosu.hpp>

#include "Game.h"
#include "Square.h"

class Twelve : public Gosu::Window
{
public:
    Twelve();
    virtual void draw() override;
    virtual bool needsCursor() const override;
    virtual void buttonDown(Gosu::Button button) override;
    virtual void buttonUp(Gosu::Button button) override;

private:
    Gosu::Font _font;
    Game _game;
};

#endif /* defined(__Twelve__Twelve__) */
