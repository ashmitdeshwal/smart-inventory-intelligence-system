
#include "PurchaseOrder.h"
#include <iostream>

PurchaseOrder::PurchaseOrder(int id, const std::string& name,
                             int quantity, int daysLeft,
                             int priorityLevel)
    : productId(id),
      productName(name),
      quantityToOrder(quantity),
      daysUntilStockout(daysLeft),
      priority(priorityLevel) {}

int PurchaseOrder::getProductId() const {
    return productId;
}

int PurchaseOrder::getQuantityToOrder() const {
    return quantityToOrder;
}

int PurchaseOrder::getDaysUntilStockout() const {
    return daysUntilStockout;
}

int PurchaseOrder::getPriority() const {
    return priority;
}

void PurchaseOrder::display() const {
    std::cout << "Product: " << productName
              << " | ID: " << productId
              << " | Order quantity: " << quantityToOrder
              << " | Days until stockout: " << daysUntilStockout
              << " | Priority: " << priority << '\n';
}

bool PurchaseOrder::operator<(const PurchaseOrder& other) const {
    if (priority != other.priority) {
        return priority < other.priority;
    }

    return daysUntilStockout > other.daysUntilStockout;
}
