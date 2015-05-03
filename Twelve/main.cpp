#include <Gosu/Gosu.hpp>

class Twelve : public Gosu::Window
{
public:
    Twelve()
    :   Gosu::Window(640, 640, false)
    {
        setCaption(L"Twelve");
    }
};

int main()
{
    Twelve window;
    window.show();
}