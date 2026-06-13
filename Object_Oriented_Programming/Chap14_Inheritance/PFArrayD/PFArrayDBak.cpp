#include <iostream>
using std::cerr;

#include "PFArrayDBak.h"

PFArrayDBak::PFArrayDBak() : PFArrayD(), usedB(0) { b = new double[capacity]; }
PFArrayDBak::PFArrayDBak(int size) : PFArrayD(size), usedB(0) { b = new double[capacity]; }
PFArrayDBak::PFArrayDBak(const PFArrayDBak &object)
    // copy constructor inherited
    : PFArrayD(object), usedB(object.usedB) {
        b = new double[capacity];
        for (int i=0; i<usedB; i++) {
            a[i] = object.b[i];
        }
    }
PFArrayDBak::~PFArrayDBak() { delete [] b; }

void PFArrayDBak::backup() {
    usedB = used;
    for (int i=0; i<used; i++) {
        b[i] = a[i];
    }
}

void PFArrayDBak::restore() {
    used = usedB;
    for (int i=0; i<usedB; i++) {
        a[i] = b[i];
    }
}

PFArrayDBak &PFArrayDBak::operator= (const PFArrayDBak &rightSide) {
    // 부모 부분 복사 (a, used, capacity)
    int oldCapacity = capacity;
    PFArrayD::operator=(rightSide);
    if (oldCapacity != rightSide.capacity) {
        delete [] b;
        b = new double[rightSide.capacity];
    }

    // 자식 부분 복사 (b, usedB)
    usedB = rightSide.usedB;
    for (int i=0; i<usedB; i++) {
        b[i] = rightSide.b[i];
    }

    return *this;
}