
#ifndef PURCHASE_ORDER_H
#define PURCHASE_ORDER_H

#include <string>

class PurchaseOrder {
private:
    int productId;
    std::string productName;
    int quantityToOrder;
    int daysUntilStockout;
    int priority;

public:
    PurchaseOrder(int id, const std::string& name,
                  int quantity, int daysLeft, int priorityLevel);

    int getProductId() const;
    int getQuantityToOrder() const;
    int getDaysUntilStockout() const;
    int getPriority() const;

    void display() const;

    bool operator<(const PurchaseOrder& other) const;
};

#endif
