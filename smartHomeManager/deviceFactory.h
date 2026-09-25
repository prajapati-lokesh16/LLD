#pragma once
#include "device.h"
class DeviceFactory{
    public:
        static Device* createObject(string type,string name,string state)
        {
            if(type == "light")
                return new Light(name,state);
            else if(type == "ac")
                return new Ac(name,state);
            else if(type == "fan")
                return new Fan(name,state);
            else{
                cout << "invalid device" << endl;
                return nullptr;
            }
        }
};