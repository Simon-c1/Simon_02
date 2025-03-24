#include "item.h"
#include <string>

item::item() {
    class Item{
    public:
        std::string name;
        double net_price;
        char vat;
        int quantity;

        Item(std::string name, double net_price, char vat, int quantity);

        double getVAT() const;
        double getTotalNET() const;
        double getTotal
    };

}
