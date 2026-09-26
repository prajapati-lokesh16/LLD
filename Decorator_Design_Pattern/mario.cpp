#include <iostream>
using namespace std;

class Icharacter
{
    public:
        virtual string getAbilities() = 0;
        virtual ~Icharacter(){};
};

class Mario:public Icharacter{
    public:
        string getAbilities() override
        {
            return " Mario ";
        }
};


class Idecorator:public Icharacter{
    public:
        Icharacter* character;
        Idecorator(Icharacter* c)
        {
            this->character = c;
        }

};

class HeightUp:public Idecorator{
    public:
        HeightUp(Icharacter* c):Idecorator(c){};
        string getAbilities() override{
            return this->character->getAbilities() + " Height Up ";
        }
};

class GunPower:public Idecorator{
    public:
        GunPower(Icharacter* c):Idecorator(c){};
        string getAbilities() override{
            return this->character->getAbilities() + " Gun Power ";
        }
};

class StarPower:public Idecorator{
    public:
        StarPower(Icharacter* c):Idecorator(c){};
        string getAbilities() override{
            return this->character->getAbilities() + " Star Power ";
        }
};

int main()
{
    Icharacter* mario = new Mario();
    cout << mario->getAbilities() << endl;

    mario = new GunPower(mario);
    cout << mario->getAbilities() << endl;

    mario = new HeightUp(mario);
    cout << mario->getAbilities() << endl;

    mario = new StarPower(mario);
    cout << mario->getAbilities() << endl;

    delete mario;
    return 0;
}
