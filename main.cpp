#include "Time2.h"
#include "Item.h"
#include "Invoice.h"
#include <iostream>



int main(){

    Time t1(200);
    std::cout<< t1<< "\n";

    Time t2;
    std::cout << "Enter time (hh::mm::ss): \n";
    std::cin >> t2;

    Time t3 = t2 - t1;
    std::cout << "Difference: " << t3 << "\n";

    int seconds = t3;
    std::cout << "Seconds: " << seconds << "\n";

    Invoice inv("7770003699", "0123456789");
    inv.addItem(Item("M3 screw", 0.37, 'A', 100));
    inv.addItem(Item("2 mm drill", 2.54, 'B', 2));
    std::cout << inv << std::endl;

    return 0;
}
