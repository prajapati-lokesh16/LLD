#pragma once

class Device{
    public:
        inline static int counter = 0;
        int id;
        string name;
        string state;
        Device(string n,string s)
        {
            id = ++counter;
            this->name = n;
            this->state = s;

            cout << "created device : ["<< id << ", " << name << ", "<< state << "]"<< endl;
        }
        virtual void deviceOn() = 0;
        virtual void deviceOff() = 0;
        virtual ~Device(){};
};