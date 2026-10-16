
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
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
        cout << left << setw(8) << id
             << setw(22) << name
             << setw(12) << quantity
             << setw(12) << dailySales
             << setw(12) << deliveryDays << '\n';
    }

    bool needsRestocking() const {
        if (dailySales <= 0)
            return false;

        return quantity <= dailySales * deliveryDays;
    }

    void checkRestocking() const {
        cout << "\nProduct: " << name << '\n';

        if (dailySales <= 0) {
            cout << "Sales data unavailable or no recent sales.\n";
            return;
        }

        double daysRemaining =
            static_cast<double>(quantity) / dailySales;

        cout << fixed << setprecision(1);
        cout << "Estimated stock duration: "
             << daysRemaining << " days\n";
        cout << "Supplier delivery time: "
             << deliveryDays << " days\n";

        if (needsRestocking())
            cout << "ALERT: Restocking recommended!\n";
        else
            cout << "Status: Stock is sufficient for delivery time.\n";
    }
};

void displayInventory(const vector<Product>& products) {
    if (products.empty()) {
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

    for (const Product& product : products)
        product.display();
}

void showRestockingAlerts(const vector<Product>& products) {
    cout << "\n======= RESTOCKING ALERTS =======\n";

    bool alertFound = false;

    for (const Product& product : products) {
        if (product.needsRestocking()) {
            product.checkRestocking();
            alertFound = true;
        }
    }

    if (!alertFound)
        cout << "No restocking alerts at present.\n";
}

void addProduct(vector<Product>& products) {
    int id, quantity, dailySales, deliveryDays;
    string name;

    cout << "\nEnter product ID: ";
    if (!(cin >> id)) {
        cout << "Invalid ID.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter product name: ";
    getline(cin, name);

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

    products.emplace_back(id, name, quantity,
                          dailySales, deliveryDays);

    cout << "Product added successfully!\n";
}

int main() {
    vector<Product> products = {
        Product(101, "Medicine A", 40, 8, 7),
        Product(102, "Medicine B", 100, 5, 7),
        Product(103, "Medicine C", 10, 6, 3)
    };

    int choice;

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
                displayInventory(products);
                break;

            case 2:
                addProduct(products);
                break;

            case 3:
                showRestockingAlerts(products);
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
