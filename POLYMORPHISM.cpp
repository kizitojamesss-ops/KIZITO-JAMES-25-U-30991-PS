#include <iostream>
#include <string>

using namespace std;

// 1. Base class with a virtual function
class PaymentGateway {
public:
    virtual ~PaymentGateway() = default;
    virtual void processPayment(double amount) {
        cout << "Processing generic payment of $" << amount << "\n";
    }
};

// 2. Derived classes overriding the virtual function
class CreditCardPayment : public PaymentGateway {
public:
    void processPayment(double amount) override {
        cout << "Processing $" << amount << " via Credit Card (Visa/Mastercard).\n";
    }
};

class PayPalPayment : public PaymentGateway {
public:
    void processPayment(double amount) override {
        cout << "Processing $" << amount << " via PayPal account.\n";
    }
};

class CryptoPayment : public PaymentGateway {
public:
    void processPayment(double amount) override {
        cout << "Processing $" << amount << " via Bitcoin/Crypto wallet.\n";
    }
};

int main() {
    // 3. Create base-class pointers pointing to derived objects
    PaymentGateway* p1 = new CreditCardPayment();
    PaymentGateway* p2 = new PayPalPayment();
    PaymentGateway* p3 = new CryptoPayment();

    cout << "--- Runtime Polymorphism: Payment System ---\n";

    // 4. Demonstrate runtime polymorphism
    p1->processPayment(150.00);
    p2->processPayment(45.50);
    p3->processPayment(300.00);

    delete p1;
    delete p2;
    delete p3;

    return 0;
}