#pragma once
#include "device.h"
#include "deviceFactory.h"
#include "automate.h"
#include "deviceStateAutomation.h"


class SmartHomeManager{
    private:
        vector<Device*> device;
        Automation* automate = new DeviceAutomation();
        inline static SmartHomeManager* instance = nullptr;
        SmartHomeManager(){};
    public:
        ~SmartHomeManager(){
            for(auto dev : device)
            {
                delete dev;
            }

            instance = nullptr;
            delete automate;
        };

        SmartHomeManager(const SmartHomeManager&) = delete;
        SmartHomeManager& operator=(const SmartHomeManager&);

        void addDevice(string type,string name,string state)
        {
            Device* dev = DeviceFactory::createObject(type,name,state);
            if(dev != nullptr)
                device.push_back(dev);
            else
                cout << "Invalid device" << endl;
        }

        static SmartHomeManager* getInstance()
        {
            if(instance == nullptr)
            {
                instance = new SmartHomeManager();
            }
            return instance;
        }
        void notify(string sensor){
            for(auto dev: device)
            {
                automate->update(dev,sensor);
            }
        };
};
