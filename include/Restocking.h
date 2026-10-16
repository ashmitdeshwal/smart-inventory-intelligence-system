
#ifndef RESTOCKING_H
#define RESTOCKING_H

#include <string>
#include <vector>

struct RestockItem {
    int id;
    std::string name;
    int quantity;
    int dailySales;
    int deliveryDays;
};

class Restocking {
public:
    static void analyze(const std::vector<RestockItem>& products,
                        int bufferDays = 2);
};

#endif
