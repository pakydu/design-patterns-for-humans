#include <iostream>
#include <string>

class Sheep {
public:
    Sheep(const std::string& name, const std::string& category = "Mountain Sheep"):
        m_name(name),
        m_category(category)
    {
    }

    void SetName(const std::string& name) { m_name =name;}
    void ShowInfo(){ std::cout <<m_name<<" : " <<m_category << std::endl;}

private:
    std::string m_name;
    std::string m_category;
};

int main()
{
    Sheep jolly("Jolly");
    jolly.ShowInfo();

    Sheep dolly(jolly);
    dolly.SetName("Dolly");
    dolly.ShowInfo();

    Sheep doolly = jolly;
    doolly.SetName("Doolly");
    doolly.ShowInfo();
}