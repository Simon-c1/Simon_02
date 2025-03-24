#ifndef INVOICE_H
#define INVOICE_H

#include "Item.h"
#include <vector>
#include <iostream>


class Invoice {
    std::string sellerNIP, buyerNIP;
    std::vector<Item> items;

public:
    Invoice(const std::string& sNIP, const std::string& bNIP) : sellerNIP(sNIP), buyerNIP(bNIP) {}

    void addItem(const Item& item) { items.push_back(item); }

    void printInvoice(std::ostream& os ) const {
        os << "------------------VAT invoice------------------\n";
        os << "===============================================\n";
        os << "Seller: " << sellerNIP << "      Buyer:" << buyerNIP << "\n";
        os << "\n";
        os << "Name | Price | VAT | Qty | NetTotal | Total\n";
        os << "-----------------------------------------------\n";

        double totalNet = 0, totalGross = 0;
        for (const auto& item : items) {
            os << item << "\n";
            totalNet += item.getNetTotal();
            totalGross += item.getTotal();
        }

        os << "-----------------------------------------------\n";
        os << "Total |   |   |   |"<< totalNet<< " | "<< totalGross << "\n";
    }
};

inline std::ostream& operator<<(std::ostream& os, const Invoice& inv) {
    inv.printInvoice(os);
    return os;
}

#endif // INVOICE_H
