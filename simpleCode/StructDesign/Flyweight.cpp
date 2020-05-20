#include <iostream>
#include <string>
#include <unordered_map>

class KaraKTea {};

class TeaMaker {
public:
    KaraKTea* Make(const std::string& preference) 
    {
        if (m_availableTea.find(preference) == m_availableTea.end())
            m_availableTea.insert({preference, new KaraKTea()});

        return m_availableTea.at(preference);
    }

private:
    std::unordered_map<std::string, KaraKTea*> m_availableTea;
};


class TeaShop {
public:
    TeaShop(TeaMaker& teamaker): m_teaMaker(teamaker) {}
    void TakeOrder(const std::string& teaType, int table)
    {
        m_orders[table] = m_teaMaker.Make(teaType);
    }

    void Serve()
    {
        for(auto order: m_orders)
            std::cout << "Serving tea to table#" << order.first << std::endl;
    }

private:
    std::unordered_map<int, KaraKTea*> m_orders;
    TeaMaker& m_teaMaker;
};


int main()
{
    TeaMaker teamaker;
    TeaShop shop(teamaker);

    shop.TakeOrder("less sugar", 1);
    shop.TakeOrder("more milk", 2);
    shop.TakeOrder("without sugar", 5);


    shop.Serve();
}