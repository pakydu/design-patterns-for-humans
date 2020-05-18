#include <iostream>
#include <string>

class ITheme {
public:
    virtual std::string GetColor() = 0;
};

class DarkTheme: public ITheme {
public:
    std::string GetColor() override {return "Dark Black";}
};

class LightTheme: public ITheme {
public: std::string GetColor() override { return "Off white";}
};

class AquaTheme: public ITheme {
public:
    std::string GetColor() override { return "Light blue";}
};

class IWebPage {
public:
    IWebPage(ITheme& theme): m_theme(theme){}
    virtual std::string GetContent() = 0;

protected:
    ITheme& m_theme;
};

class About: public IWebPage {
public:
    About(ITheme& theme): IWebPage(theme) {}
    std::string GetContent() override {
        return "About page in " + m_theme.GetColor();
    }
};

class Careers: public IWebPage {
public:
    Careers(ITheme& theme): IWebPage(theme) {}
    std::string GetContent() override {
        return "Careers page in " + m_theme.GetColor();
    }
};

int main()
{
    DarkTheme darkTheme;

    About about(darkTheme);
    Careers careers(darkTheme);

    std::cout << about.GetContent() << std::endl;
    std::cout << careers.GetContent() << std::endl;
}