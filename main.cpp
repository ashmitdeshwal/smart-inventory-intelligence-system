
#include <iostream>
#include <string>
#include <limits>
#include "Restocking.h"

using namespace std;

const int MAX_PRODUCTS = 100;



    string name;
    int quantity;
    int dailySales;
    int deliveryDays;
};

void displayInventory(const Product p[], int n) {
    if (n == 0) {
        cout << "Inventory is empty.\n";
        return;
    }

    cout << "\nID\tProduct\t\tStock\tSales/Day\tDelivery\n";

    for (int i = 0; i < n; i++) {
        cout << p[i].id << '\t' << p[i].name << '\t'
             << p[i].quantity << '\t' << p[i].dailySales
             << '\t' << p[i].deliveryDays << '\n';
    }
}

void addProduct(Product p[], int& n) {
    if (n >= MAX_PRODUCTS) {
        cout << "Inventory is full.\n";
        return;
    }

    Product item;

    cout << "Enter ID: ";
    if (!(cin >> item.id) || item.id <= 0) {
        cout << "Invalid ID.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    for (int i = 0; i < n; i++) {
        if (p[i].id == item.id) {
            cout << "ID already exists.\n";
            return;
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter product name: ";
    getline(cin, item.name);

    cout << "Enter stock, daily sales and delivery days: ";
    if (!(cin >> item.quantity >> item.dailySales >> item.deliveryDays)
        || item.quantity < 0 || item.dailySales < 0
        || item.deliveryDays < 0 || item.name.empty()) {
        cout << "Invalid product details.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    p[n++] = item;
    cout << "Product added successfully.\n";
}

void showAlerts(const Product p[], int n) {
    RestockItem items[MAX_PRODUCTS];

    for (int i = 0; i < n; i++) {
        items[i] = {p[i].id, p[i].name, p[i].quantity,
                    p[i].dailySales, p[i].deliveryDays};
    }

    Restocking::analyze(items, n);
}

int main() {
    Product products[MAX_PRODUCTS] = {
        {101, "Medicine A", 40, 8, 7},
        {102, "Medicine B", 100, 5, 7},
        {103, "Medicine C", 10, 6, 3}
    };

    int count = 3, choice;

    do {
        cout << "\n=== SMART INVENTORY SYSTEM ===\n"
             << "1. Display Inventory\n"
             << "2. Add Product\n"
             << "3. Restocking Alerts\n"
             << "4. Exit\n"
             << "Choice: ";

        if (!(cin >> choice)) {
            cout << "Enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
            case 1: displayInventory(products, count); break;
            case 2: addProduct(products, count); break;
            case 3: showAlerts(products, count); break;
            case 4: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
