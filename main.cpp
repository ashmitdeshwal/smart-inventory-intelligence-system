
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "Restocking.h"

using namespace std;

const int MAX_PRODUCTS = 100;

class Product {
private:
    int id;
    string name;
    int quantity;
    int dailySales;
    int deliveryDays;

public:
    Product()
        : id(0), name(""), quantity(0),
          dailySales(0), deliveryDays(0) {}

    Product(int id, const string& name, int quantity,
            int dailySales, int deliveryDays)
        : id(id), name(name), quantity(quantity),
          dailySales(dailySales), deliveryDays(deliveryDays) {}

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    int getDailySales() const {
        return dailySales;
    }

    int getDeliveryDays() const {
        return deliveryDays;
    }

    void display() const {
        cout << left << setw(8) << id
             << setw(22) << name
             << setw(12) << quantity
             << setw(12) << dailySales
             << setw(12) << deliveryDays << '\n';
    }
};

void displayInventory(const Product products[], int count) {
    if (count == 0) {
        cout << "\nInventory is empty.\n";
        return;
    }

    cout << "\n========== INVENTORY ==========\n";
    cout << left << setw(8) << "ID"
         << setw(22) << "Product"
         << setw(12) << "Stock"
         << setw(12) << "Sales/Day"
         << setw(12) << "Delivery" << '\n';

    cout << string(66, '-') << '\n';

    for (int i = 0; i < count; i++) {
        products[i].display();
    }
}

void showRestockingAlerts(const Product products[], int count) {
    RestockItem inventory[MAX_PRODUCTS];

    for (int i = 0; i < count; i++) {
        inventory[i] = {
            products[i].getId(),
            products[i].getName(),
            products[i].getQuantity(),
            products[i].getDailySales(),
            products[i].getDeliveryDays()
        };
    }

    cout << "\n======= SMART RESTOCKING ANALYSIS =======\n";
    Restocking::analyze(inventory, count);
}

void addProduct(Product products[], int& count) {
    if (count >= MAX_PRODUCTS) {
        cout << "Inventory is full. Cannot add more products.\n";
        return;
    }

    int id, quantity, dailySales, deliveryDays;
    string name;

    cout << "\nEnter product ID: ";

    if (!(cin >> id) || id <= 0) {
        cout << "Invalid product ID.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < count; i++) {
        if (products[i].getId() == id) {
            cout << "This product ID already exists.\n";
            return;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter product name: ";
    getline(cin, name);

    if (name.empty()) {
        cout << "Product name cannot be empty.\n";
        return;
    }

    cout << "Enter current stock: ";

    if (!(cin >> quantity) || quantity < 0) {
        cout << "Invalid stock quantity.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "Enter average daily sales: ";

    if (!(cin >> dailySales) || dailySales < 0) {
        cout << "Invalid daily sales.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "Enter supplier delivery days: ";

    if (!(cin >> deliveryDays) || deliveryDays < 0) {
        cout << "Invalid delivery time.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    products[count] = Product(
        id, name, quantity, dailySales, deliveryDays
    );

    count++;
    cout << "Product added successfully!\n";
}

int main() {
    Product products[MAX_PRODUCTS] = {
        Product(101, "Medicine A", 40, 8, 7),
        Product(102, "Medicine B", 100, 5, 7),
        Product(103, "Medicine C", 10, 6, 3)
    };

    int productCount = 3;
    int choice = 0;

    cout << "SMART INVENTORY INTELLIGENCE SYSTEM\n";

    do {
        cout << "\n========== MAIN MENU ==========\n";
        cout << "1. Display Inventory\n";
        cout << "2. Add Product\n";
        cout << "3. Check Restocking Alerts\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1:
                displayInventory(products, productCount);
                break;

            case 2:
                addProduct(products, productCount);
                break;

            case 3:
                showRestockingAlerts(products, productCount);
                break;

            case 4:
                cout << "Exiting system. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
