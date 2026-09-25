#pragma once

class Automation{
    public:
        Automation(){};
       virtual void update(Device* device,string sensor) = 0;
};