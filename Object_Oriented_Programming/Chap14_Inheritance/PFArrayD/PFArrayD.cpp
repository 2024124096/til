#include <iostream>
using std::cerr;

#include "PFArrayD.h"

PFArrayD::PFArrayD() : capacity(50), used(0) { a = new double[capacity]; }
PFArrayD::PFArrayD(int size) : capacity(size), used(0) { a = new double[capacity]; }
PFArrayD::PFArrayD(const PFArrayD &pfaObject)
    : capacity(pfaObject.capacity), used(pfaObject.used) {
        a = new double[capacity];
        for (int i=0; i<used; i++) {
            a[i] = pfaObject.a[i];
        }
    }
PFArrayD::~PFArrayD() { delete [] a; }

int PFArrayD::getNumberUsed() const { return used; }
void PFArrayD::addElement(double element) {
    if (used >= capacity) {
        cerr << "Attempt to exceed capacity in PFArrayD.\n";
        }
    a[used++] = element;
}
bool PFArrayD::full() const { return (capacity==used); }
void PFArrayD::emptyArray() { used = 0; }

double &PFArrayD::operator [](int index) const {
    if (index < 0 || index >= used) {
        cerr << "Illegal index in PFArrayD.\n";
        exit(1);
    }
    return a[index];
}

// deep copy
PFArrayD &PFArrayD::operator= (const PFArrayD &rightSide) {
    if (capacity != rightSide.capacity) {
        delete [] a;
        a = new double[rightSide.capacity];
    }

    capacity = rightSide.capacity;
    used = rightSide.used;

    for (int i=0; i<used; i++) {
        a[i] = rightSide.a[i];
    }

    return *this;
}