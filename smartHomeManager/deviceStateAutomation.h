#pragma once

class DeviceAutomation:public Automation{
    public:
        DeviceAutomation():Automation(){};
        void update(Device* device,string sensor) override
        {
            if(sensor == "on")
                device->deviceOn();
            else
                device->deviceOff();
        };
};