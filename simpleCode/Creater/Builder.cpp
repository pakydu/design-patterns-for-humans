#include <iostream>

class Burger {
public:
    class BurgerBuilder;
    void showFlavors()
    {
        std::cout << m_size;
        if (m_cheese)
            std::cout << "-cheese";
        if (m_peperoni)
            std::cout << "-peperoni";
        if (m_lettuce)
            std::cout << "-lettuce";
        if (m_tomato)
            std::cout << "-tomato";
        std::cout <<std::endl;
    }

private:
    Burger(int size): m_size(size){}
    int m_size = 7;
    bool m_cheese = false;
    bool m_peperoni = false;
    bool m_lettuce = false;
    bool m_tomato = false;
};

class Burger::BurgerBuilder {
public:
    BurgerBuilder(int size) {m_burger = new Burger(size);}
    BurgerBuilder& AddChesse() {m_burger->m_cheese = true; return *this;}
    BurgerBuilder& AddPepperoni() {m_burger->m_peperoni = true; return *this;}
    BurgerBuilder& AddLettuce() {m_burger->m_lettuce = true; return *this;}
    BurgerBuilder& AddTomato() {m_burger->m_tomato = true; return *this;}

    Burger* Build() { return m_burger;}


private:
    Burger * m_burger;
};


int main()
{
    Burger* burger = Burger::BurgerBuilder(14).AddPepperoni().AddChesse().AddTomato().Build();
    burger->showFlavors();    
}