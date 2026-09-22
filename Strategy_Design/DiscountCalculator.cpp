#include<iostream>
using namespace std;

class DiscountStrategy{
    public:
        virtual double discount(double amount) = 0;
        virtual ~DiscountStrategy(){}
};

class NoDiscount : public DiscountStrategy{
    public:
        double discount(double amount) override
        {
            return amount;
        }
};

class FlatDiscount : public DiscountStrategy{
    public:
        double discount(double amount) override
        {
            return amount * 0.85;
        }
};

class SeasonalDiscount : public DiscountStrategy{
    public:
        double discount(double amount) override
        {
            if(amount > 2000.0)
            {
                return amount - 500.0;
            }
            return amount;
        }
};

class VipDiscount : public DiscountStrategy{
    public:
        double discount(double amount) override
        {
            return amount * 0.70;
        }
};


class ShoppingCart{
    DiscountStrategy* d;

    public:
        ShoppingCart(DiscountStrategy*discount)
        {
            this->d = discount;
        }

        void setDiscountStrategy(DiscountStrategy*discount)
        {
            this->d = discount;
        }

        double calculateTotal(double amount)
        {
            return d->discount(amount);
        }
};



int main()
{
    //Creating objects using heap allocation
    double amount = 5000;
    ShoppingCart* fd = new ShoppingCart(new FlatDiscount());
    cout <<"Flat Discount : " << fd->calculateTotal(amount) << endl;
    
    ShoppingCart* nd = new ShoppingCart(new NoDiscount());
    cout <<"No Discount : " << nd->calculateTotal(amount) << endl;

    //Creating objects using stack allocation
    ShoppingCart cart = new VipDiscount();
    cout <<"VIP Discount : " << cart.calculateTotal(amount) << endl;

    //Changing the discount by reusing a same object at runtime
    cart.setDiscountStrategy(new SeasonalDiscount());
    cout <<"Seasonal Discount : " << cart.calculateTotal(amount) << endl;
    return 0;
}