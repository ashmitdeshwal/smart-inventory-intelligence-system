
#include "Restocking.h"
#include "Alert.h"
#include "PurchaseOrder.h"

#include <iostream>
#include <queue>
#include <algorithm>

void Restocking::analyze(const std::vector<RestockItem>& products,
                         int bufferDays) {
    if (bufferDays < 0) {
        std::cout << "Buffer days cannot be negative.\n";
        return;
    }

    std::priority_queue<PurchaseOrder> orders;
    bool foundLowStock = false;

    for (const RestockItem& product : products) {
        if (product.quantity < 0 ||
            product.dailySales < 0 ||
            product.deliveryDays < 0) {
            std::cout << "Invalid inventory data for "
                      << product.name << ". Skipping.\n";
            continue;
        }

        if (product.dailySales == 0) {
            continue;
        }

        int daysLeft = product.quantity / product.dailySales;
        int reorderPoint =
            product.dailySales * (product.deliveryDays + bufferDays);

        if (product.quantity > reorderPoint) {
            continue;
        }

        foundLowStock = true;

        int orderQuantity = std::max(
            0,
            reorderPoint - product.quantity
        );

        int priority;

        if (daysLeft <= product.deliveryDays) {
            priority = 3;
        } else if (daysLeft <= product.deliveryDays + 2) {
            priority = 2;
        } else {
            priority = 1;
        }

        std::string severity;
        if (priority == 3) {
            severity = "CRITICAL";
        } else if (priority == 2) {
            severity = "HIGH";
        } else {
            severity = "MEDIUM";
        }

        Alert alert(
            product.id,
            product.name,
            "Low stock. Estimated stockout in " +
                std::to_string(daysLeft) + " day(s).",
            severity
        );

        alert.display();

        orders.push(PurchaseOrder(
            product.id,
            product.name,
            orderQuantity,
            daysLeft,
            priority
        ));
    }

    if (!foundLowStock) {
        std::cout << "No restocking alerts. Inventory is sufficient.\n";
        return;
    }

    std::cout << "\nRestocking queue (highest priority first):\n";

    while (!orders.empty()) {
        orders.top().display();
        orders.pop();
    }
}
