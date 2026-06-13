#include <string>
#include <iostream>
#include "HourlyEmployee.h"

using std::string;
using std::cout;
using std::endl;

namespace Employee1102 {
    //contructor
        // The constructors of the base class in the constructors of the derived class
    HourlyEmployee::HourlyEmployee() : Employee(), wageRate(0.0), hours(0.0) { }
    HourlyEmployee::HourlyEmployee(const string &name, const string &ssn,
                                    double wageRate, double hours)
        : Employee(name, ssn), wageRate(wageRate), hours(hours) { }
    
    // getter
    double HourlyEmployee::getRate() const { return wageRate; }
    double HourlyEmployee::getHours() const { return hours; }

    // setter
    void HourlyEmployee::setRate(double newWageRate) { wageRate = newWageRate; }
    void HourlyEmployee::setHours(double newHours) { hours = newHours; }

    void HourlyEmployee::printCheck() {
        cout << "Pay to the order of " << getName() << endl
             << "The sum of " << getNetPay() << " Dollars\n";

        cout << "Check Stub: NOT NEGOTIABLE\n";
        cout << "Employee Number: " << getSsn() << endl;
        cout << "Hourly Employee.\nHourss worked: " << hours
             << " Rate: " << wageRate << " Pay: " << getNetPay() << endl;
    }
} // end namespace Employee1102