
#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    int quantity;
    int dailySales;
    int deliveryDays;

public:
    Product(int id, string name, int quantity,
            int dailySales, int deliveryDays) {
        this->id = id;
        this->name = name;
        this->quantity = quantity;
        this->dailySales = dailySales;
        this->deliveryDays = deliveryDays;
    }

    void display() const {
        cout << "\nProduct ID: " << id;
        cout << "\nName: " << name;
        cout << "\nCurrent Stock: " << quantity;
        cout << "\nDaily Sales: " << dailySales;
        cout << "\nDelivery Days: " << deliveryDays << '\n';
    }

    void checkRestocking() const {
        cout << "\nRestocking Analysis for " << name << ":\n";

        if (dailySales <= 0) {
            cout << "Sales data unavailable; risk cannot be calculated.\n";
            return;
        }

        int daysRemaining = quantity / dailySales;

        cout << "Estimated days of stock remaining: "
             << daysRemaining << '\n';

        if (daysRemaining < deliveryDays) {
            cout << "ALERT: Restocking is recommended!\n";
        } else {
            cout << "Stock may last until delivery.\n";
        }
    }
};

int main() {
    Product medicine(101, "Medicine A", 40, 8, 7);

    cout << "SMART INVENTORY INTELLIGENCE SYSTEM\n";
    medicine.display();
    medicine.checkRestocking();

    return 0;
}
