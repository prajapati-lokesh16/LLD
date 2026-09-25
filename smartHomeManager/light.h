#pragma once
#include "device.h"


class Light:public Device{
    private:
        // int id;
        // string name;
        // string state;
    public:
        Light(string n,string s):Device(n,s){};

        void deviceOn() override
        {
            state = "On";
            cout << "Device with id : "<< this->id << ", name : "<< this->name << " is on"<< endl;
        }
        void deviceOff() override
        {
            state = "Off";
            cout << "Device with id : "<< this->id << ", name : "<< this->name << " is off"<< endl;
        }

};