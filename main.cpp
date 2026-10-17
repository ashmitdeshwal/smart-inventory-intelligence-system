
#include <iostream>
#include "Restocking.h"
using namespace std;

struct Product {
    int id, stock, sales, delivery;
    string name;
};

int main() {
    Product p[100] = {
        {101, 40, 8, 7, "MedicineA"},
        {102, 100, 5, 7, "MedicineB"},
        {103, 10, 6, 3, "MedicineC"}
    };

    int n = 3, choice;

    do {
        cout << "\n--- Smart Inventory Intelligence System ---\n";
        cout << "1. View Products\n";
        cout << "2. Add Product\n";
        cout << "3. Check Restocking Alerts\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            for (int i = 0; i < n; i++) {
                cout << p[i].id << " "
                     << p[i].name
                     << " | Stock: " << p[i].stock
                     << " | Daily Sales: " << p[i].sales
                     << " | Delivery Days: " << p[i].delivery
                     << '\n';
            }
            break;

        case 2:
            if (n >= 100) {
                cout << "Inventory is full.\n";
                break;
            }

            cout << "Enter ID, stock, daily sales, delivery days, name: ";
            cin >> p[n].id >> p[n].stock
                >> p[n].sales >> p[n].delivery
                >> p[n].name;
            n++;
            cout << "Product added successfully.\n";
            break;

        case 3: {
            RestockItem items[100];

            for (int i = 0; i < n; i++) {
                items[i] = {
                    p[i].id,
                    p[i].name,
                    p[i].stock,
                    p[i].sales,
                    p[i].delivery
                };
            }

            Restocking::analyze(items, n);
            break;
        }

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
