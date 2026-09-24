#include <iostream>
using namespace std;

class Logging{
    private:
        static Logging* logInstance;

        Logging()
        {
            cout << "Log is created"<< endl;
        }

    public:
        Logging(const Logging&) = delete;
        Logging& operator=(const Logging&);
        
        static Logging* getInstance()
        {
            if(logInstance == nullptr)
            {
                logInstance = new Logging();
            }

            return logInstance;
        }
};

Logging* Logging::logInstance = nullptr;


int main()
{
    Logging* l1 = Logging::getInstance();
    Logging* l2 = Logging::getInstance();

    cout << (l1 == l2);
}