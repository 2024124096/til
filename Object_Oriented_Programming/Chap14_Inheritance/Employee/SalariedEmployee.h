#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include <string>
#include "Employee.h"

using std::string;

namespace Employee1102 {
    class SalariedEmployee : public Employee {
        public:
            // constructor
            SalariedEmployee();
            SalariedEmployee(const string &name, const string &ssn,
                            double weeklySalary);

            // getter
            double getSalary() const;
            
            // setter
            void setSalary(double newWeeklySalary);
            
            // printCheck() is redefined
                // in a different way than in the other derived class
            void printCheck();
        
        private:
            double weeklySalary;
    }; // end SalariedEmployee
} // end namespace Employee1102

#endif