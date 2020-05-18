#include <iostream>
#include <string>
#include <unistd.h>



class ICoffee {
public:
    virtual ~ICoffee() { std::cout << "bye, ICoffee" << std::endl;}
    virtual float GetCost() = 0;
    virtual std::string GetDescription() = 0;
};

class SimpleCoffee: public ICoffee {
public:
    ~SimpleCoffee() { std::cout << "bye, Simplecoffee" << std::endl;}
    float GetCost() override { return 0;}
    std::string GetDescription() override { return "Simple coffee";}
};

class CoffeePlus: public ICoffee {
public:
    CoffeePlus(ICoffee& coffee): m_coffee(coffee) {}
    ~CoffeePlus() {  std::cout << "bye, CoffeePlus" << std::endl;}
    virtual float GetCost() = 0;
    virtual std::string GetDescription() = 0;

protected:
    ICoffee& m_coffee;
};

class MilkCoffee: public CoffeePlus {
public:
    MilkCoffee(ICoffee& coffee):CoffeePlus(coffee) {}
    ~MilkCoffee() {  std::cout << "bye, MilkCoffee" << std::endl;}
    float GetCost() override { return m_coffee.GetCost() + 2;}
    std::string GetDescription() override { return  m_coffee.GetDescription() + ", milk"; }
};


class WhipCoffee: public CoffeePlus {
public:
    WhipCoffee(ICoffee& coffee):CoffeePlus(coffee) {}
    ~WhipCoffee() {  std::cout << "bye, WhipCoffee" << std::endl;}
    float GetCost() override { return m_coffee.GetCost() + 5;}
    std::string GetDescription() override { return  m_coffee.GetDescription() + ", Whip";}
};

class VanillCoffee: public CoffeePlus {
public:
    VanillCoffee(ICoffee& coffee):CoffeePlus(coffee) {}
    ~VanillCoffee() {  std::cout << "bye, VanillCoffee" << std::endl;}
    float GetCost() override { return m_coffee.GetCost() + 3;}
    std::string GetDescription() override { return  m_coffee.GetDescription() + ", Vanill";}
};

int main()
{
    ICoffee* someCoffee = new SimpleCoffee();
    std::cout << someCoffee->GetCost() <<std::endl;
    std::cout << someCoffee->GetDescription() << std::endl;

    ICoffee* someCoffee2 = new MilkCoffee(*someCoffee);

    std::cout << someCoffee->GetCost() <<std::endl;
    std::cout << someCoffee->GetDescription() << std::endl;

    ICoffee* someCoffee3 = new WhipCoffee(*someCoffee);
    
    std::cout << someCoffee->GetCost() <<std::endl;
    std::cout << someCoffee->GetDescription() << std::endl;


    ICoffee* someCoffee4 = new VanillCoffee(*someCoffee);
    
    std::cout << someCoffee->GetCost() <<std::endl;
    std::cout << someCoffee->GetDescription() << std::endl;

    delete someCoffee4;
    delete someCoffee3;
   

    delete someCoffee2;
    delete someCoffee;


    sleep(100000);

}