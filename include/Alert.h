
#ifndef ALERT_H
#define ALERT_H

#include <string>

class Alert {
private:
    int productId;
    std::string productName;
    std::string message;
    std::string severity;

public:
    Alert(int id, const std::string& name,
          const std::string& msg, const std::string& level);

    void display() const;
};

#endif
