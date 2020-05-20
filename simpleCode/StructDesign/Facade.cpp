#include <iostream>

class Computer {
public: 
    void GetElectricShock() { std::cout << "Ouch!" << std::endl;}
    void MakeSound() { std::cout << "Beep beep!" << std::endl;}
    void ShowLoadingScreen() { std::cout << "Loading..." << std::endl;}
    void Bam() { std::cout << "Ready to be used!" << std::endl;}
    void CloseEveryting() { std::cout << "Bup bup bup buzzz!" << std::endl;}
    void Sooth() { std::cout << "Zzzzz" << std::endl;}
    void PullCurrent() { std::cout << "Haah!" << std::endl;}
};

class ComputerFacade {
public:
    ComputerFacade(Computer& computer): m_computer(computer) {}

    void TurnOn()
    {
        m_computer.GetElectricShock();
        m_computer.MakeSound();
        m_computer.ShowLoadingScreen();
        m_computer.Bam();
    }

    void TurnOff()
    {
        m_computer.CloseEveryting();
        m_computer.PullCurrent();
        m_computer.Sooth();
    }

private:
    Computer& m_computer;
};


int main()
{
    Computer real_computer;
    ComputerFacade computer(real_computer);

    computer.TurnOn();
    std::cout << "running...." << std::endl;
    computer.TurnOff();
}