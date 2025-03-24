#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>


class Item {
    std::string name;
    double unitPrice;
    char vatType;
    int quantity;

public:
    Item(std::string n, double up, char vt, int q) : name(n), unitPrice(up), vatType(vt), quantity(q) {}

    std::string getName() const { return name;}
    double getUnitPrice() const { return unitPrice; }
    char getVatType() const { return vatType; }
    int getQuantity() const {return quantity; }

    double getNetTotal() const { return unitPrice * quantity; }

    double getVatMul() const {
        if (vatType == 'A') return 1.23;
        if (vatType == 'B') return 1.08;
        return 0;
    }

    double getTotal() const {
        return getNetTotal() * getVatMul();
    }

    void printItem(std::ostream& os) const {
        os << name << " | "
           << unitPrice << " | "
           << vatType << " | "
           << quantity << " | "
           << getNetTotal() << " | "
           << getTotal();
    }
};

inline std::ostream& operator<<(std::ostream& os, const Item& item) {
    item.printItem(os);
    return os;
}
#endif // ITEM_H
