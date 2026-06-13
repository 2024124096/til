#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using std::string;

namespace Employee1102 {
    class Employee {
        public:
            // constructor
            Employee();
            Employee(const string &name, const string &ssn);

            // getter
            string getName() const;
            string getSsn() const;
            double getNetPay() const;
            
            // setter
            void setName(const string &newName);
            void setSsn(const string &newSsn);
            void setNetPay(double newNetPay);
            
            void printCheck() const;
        
        private:
            string name;
            string ssn;
            double netPay;
    }; // end Employee
} // end namespace Employee1102

#endif