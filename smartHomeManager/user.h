#pragma once
#include "smartHomeManager.h"

class User{
    private:
        string name;
        int id;
        inline static int counter = 0;
        SmartHomeManager* manager = SmartHomeManager::getInstance();

    public:
        User(string name)
        {
            id = ++counter;
            this->name = name;
            cout << "Created user :[" << id << ", " << name << "]" << endl;
        }

        void addDevice(string type,string name,string state)
        {
            manager->addDevice(type,name,state);
            cout << "Device added successfully" << endl;
        }

        void userAvailable(string s)
        {
            if(s == "yes")
            {
                manager->notify("on");
            }
            else if(s == "no"){
                manager->notify("off");
            }
            else{
                cout << "Invalid input" << endl;
            }
        }
};