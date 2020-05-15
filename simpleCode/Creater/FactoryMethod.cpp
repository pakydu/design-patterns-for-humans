#include <iostream>

class IInterview {
public:
    virtual void askQuestions() = 0;
};

class Developer: public IInterview {
public:
    void askQuestions() override {
        std::cout << "Asking about design patternes!" << std::endl;
    }
};

class CommuityExecutive: public IInterview {
public:
    void askQuestions() override {
        std::cout << "Asking about community buiding!" << std::endl;
    }
};

class HiringManager {
public:
    void takeInterview()
    {
        IInterview *interviewer = this->makeInterviewer();
        interviewer->askQuestions();
    }

protected:
    virtual IInterview *makeInterviewer() = 0;
};

template <typename Interviewer>
class OtherManager: public HiringManager {
public:
    IInterview *makeInterviewer() override 
    {
        return new Interviewer();
    }
};

int main()
{
    HiringManager *devManager = new OtherManager<Developer>();
    devManager->takeInterview();

    HiringManager *marketManager = new OtherManager<CommuityExecutive>();
    marketManager->takeInterview();
}
