
#include "Alert.h"
#include <iostream>

Alert::Alert(int id, const std::string& name,
             const std::string& msg, const std::string& level)
    : productId(id),
      productName(name),
      message(msg),
      severity(level) {}

void Alert::display() const {
    std::cout << "[" << severity << "] "
              << productName
              << " (ID: " << productId << "): "
              << message << '\n';
}
