#include <string>
#include <iostream>
#include "SalariedEmployee.h"

using std::string;
using std::cout;
using std::endl;

namespace Employee1102 {
    //contructor
    SalariedEmployee::SalariedEmployee() : Employee(), weeklySalary(0.0) { }
    SalariedEmployee::SalariedEmployee(const string &name, const string &ssn,
                                    double weeklySalary)
        : Employee(name, ssn), weeklySalary(weeklySalary) { }
    
    // getter
    double SalariedEmployee::getSalary() const { return weeklySalary; }

    // setter
    void SalariedEmployee::setSalary(double newWeeklySalary) { weeklySalary = newWeeklySalary; }

    void SalariedEmployee::printCheck() {
        cout << "Pay to the order of " << getName() << endl
             << "The sum of " << getNetPay() << " Dollars\n";
        
        cout << "Check Stub: NOT NEGOTIABLE\n";
        cout << "Employee Number: " << getSsn() << endl;
        cout << "Salaried Employee. Regualr Pay: " << getNetPay() << endl;
    }
} // end namespace Employee1102