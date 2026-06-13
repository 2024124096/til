#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include <string>
#include "Employee.h"

using std::string;

namespace Employee1102 {
    // Inheritance is indicated by the class name followed by a colon (:),
        // “public” (reserved word), and then the base class name
    class HourlyEmployee : public Employee {
        public:
            // constructor
            HourlyEmployee();
            HourlyEmployee(const string &name, const string &ssn,
                            double wageRate, double hours);

            // getter
            double getRate() const;
            double getHours() const;
            
            // setter
            void setRate(double newWageRate);
            void setHours(double hours);
            
            // printCheck() is redefined (no const modifier)
            void printCheck();
        
        private:
            double wageRate;
            double hours;
    }; // end HourlyEmployee
} // end namespace Employee1102

#endif