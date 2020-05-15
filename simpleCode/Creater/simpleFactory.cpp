#include <iostream>

class IDoor{
public:
    virtual float GetWidth() = 0;
    virtual float GetHeigh() = 0;
};


class WoodenDoor: public IDoor {
public:
    WoodenDoor(float width, float heigth):m_width(width), m_height(heigth){};
    float GetWidth() override {return m_width;}
    float GetHeigh() override {return m_height;}

protected:
    float m_width;
    float m_height;
};

class DoorFactory {
public:
    static IDoor *MakeDoor(float width, float heigh)
    {
        return new WoodenDoor(width, heigh);
    }
};

int main()
{
    IDoor *door = DoorFactory::MakeDoor(100, 200);
    std::cout << "Width: " << door->GetHeigh() << std::endl;
    std::cout << "Heigh: " << door->GetHeigh() << std::endl;
}
