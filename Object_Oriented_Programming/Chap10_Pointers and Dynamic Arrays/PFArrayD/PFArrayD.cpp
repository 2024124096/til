#include <iostream>
using namespace std;

#include "PFArrayD.h"

void PFArrayD::addElement(double element) {
    // Capacity check is implemented based on abstraction
    if (used >= capacity) {
        cerr << "Attempt to exceed capacity in PFArrayD.\n";
        exit(1);
    }
    a[used++] = element;
}

double &PFArrayD::operator[](int index) {
    // "Reference" to a double is returned,
        // so that return value can be used as an lvalue
    if (index < 0 || index >= used) {
        cerr << "Illegal index in PFArrayD.\n";
        exit(1);
    }
    return a[index];
}

PFArrayD &PFArrayD::operator=(const PFArrayD &rightSide) {
    // Reference of a PFArrayD object is returned
    if (capacity != rightSide.capacity) {
        delete [] a;
        a = new double[rightSide.capacity];
    }

    capacity = rightSide.capacity;
    used = rightSide.used;
    for (int i=0; i<used; i++) {
        a[i] = rightSide.a[i];
        // a = rightSide.a; 하면 안됨. 얕은복사!
            // 반드시 새 배열을 싸로 할당하고 값을 하나씩 복사해
                // this->a와 rightSide.a를 별도의 힙 배열로 저장해두어야 함
    }

    return *this;
}

PFArrayD::PFArrayD(const PFArrayD &pfaObject)
    : capacity(pfaObject.capacity), used(pfaObject.used) {
        a = new double[capacity];
        for (int i=0; i<used; i++) {
            a[i] = pfaObject.a[i];
        }
    }

PFArrayD::~PFArrayD() {
    delete [] a;
}