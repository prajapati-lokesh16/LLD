#include<iostream>
using namespace std;

class Notification{
    public:
        virtual void message() = 0;
        virtual ~Notification(){};
};

class PushNotification : public Notification{
    public:
        void message() override
        {
            cout << "I am a push Notification"<< endl;
        }
};

class SmsNotification : public Notification{
    public:
        void message() override
        {
            cout << "I am a SMS Notification"<< endl;
        }
};

class EmailNotification : public Notification{
    public:
        void message() override
        {
            cout << "I am a Email Notification"<< endl;
        }
};


class NotificationFactory{
    public:
        Notification* createNotification(string type)
        {
            if(type == "push")
            {
                return new PushNotification();
            }
            else if(type == "sms")
            {
                return new SmsNotification();
            }
            else if(type == "email")
            {
                return new EmailNotification();
            }
            else{
                cout << "Invalid Notification type!" << endl;
                return nullptr;
            }
        }
};

int main()
{
    string type = "sms";
    NotificationFactory* notiFact = new NotificationFactory();
    Notification* notification = notiFact->createNotification(type);
    notification->message();
    return 0;
}