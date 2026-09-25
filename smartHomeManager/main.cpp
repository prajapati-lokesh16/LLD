#include<iostream>
#include<vector>
#include<string>
using namespace std;

#include "device.h"
#include "light.h"
#include "fan.h"
#include "ac.h"
#include "smartHomeManager.h"
#include "deviceFactory.h"
#include "automate.h"
#include "deviceStateAutomation.h"
#include "user.h"


using namespace std;

int main()
{
    User* user = new User("Lokesh");
    user->addDevice("light","L1","on");
    user->addDevice("fan","f1","on");
    user->addDevice("ac","a1","on");
    user->addDevice("light","L2","on");

    user->userAvailable("yes");
    user->userAvailable("no");


    return 0;
}