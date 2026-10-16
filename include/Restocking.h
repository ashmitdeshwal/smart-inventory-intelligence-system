
#ifndef RESTOCKING_H
#define RESTOCKING_H

#include <string>

struct RestockItem {
    int id;
    std::string name;
    int quantity;
    int dailySales;
    int deliveryDays;
};

class Restocking {
public:
    static void analyze(const RestockItem products[],
                        int count,
                        int bufferDays = 2);
};

#endif
