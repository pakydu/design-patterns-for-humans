#include <iostream>
#include <string>
#include <cassert>


class President {
public:
    static President& GetInstance()
    {
        static President instance;
        return instance;
    }
    President(const President&) = delete;
    President& operator=(const President&) = delete;
private:
    President() {}
};


int main()
{
    const President& pre1 = President::GetInstance();
    const President& pre2 = President::GetInstance();

    assert(&pre1 == &pre2);
}