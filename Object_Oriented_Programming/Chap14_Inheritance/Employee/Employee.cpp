#include <string>
#include <cstdlib>
#include <iostream>
#include "Employee.h"

using std::string;
using std::cerr;

namespace Employee1102 {
    //contructor
    Employee::Employee() : name("No name yet"), ssn("No number yet"), netPay(0.0) { }
    Employee::Employee(const string &name, const string &ssn)
        : name(name), ssn(ssn), netPay(0.0) { }
    
    // getter
    string Employee::getName() const { return name; }
    string Employee::getSsn() const { return ssn; }

    // setter
    void Employee::setName(const string &newName) { name = newName; }
    void Employee::setSsn(const string &newSsn) { ssn = newSsn; }
    void Employee::setNetPay(double newNetPay) { netPay = newNetPay; }

    void Employee::printCheck() const {
        cerr << "\nERROR: printCheck FUNCTION CALLED FOR AN \n"
             << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
             << "Check with the author of the program about this bug.\n";
        exit(1);
    }
} // end namespace Employee1102