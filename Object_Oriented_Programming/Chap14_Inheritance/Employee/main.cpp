#include <iostream>
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"

using std::cout;
using std::endl;
using Employee1102::HourlyEmployee;
using Employee1102::SalariedEmployee;

int main() {
    HourlyEmployee joe;
    joe.setName("Mighty Joe");
    joe.setSsn("123-35-335");
    joe.setRate(20.50);
    joe.setHours(40);

    cout << "Check for " << joe.getName()
         << " for " << joe.getHours() << " hours.\n";
    joe.printCheck();
    cout << endl;
    
    SalariedEmployee boss("Mr. Big Shot", "824-245-435", 1443.04);
    cout << "Check for " << boss.getName() << endl;
    boss.printCheck();

    return 0;
}