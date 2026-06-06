#include <iostream>
using namespace std;

class StringClass {
    public:
        void someProcessing();
        StringClass &operator =(const StringClass &rtside);
    private:
        char *a;
        int capacity;
        int length;
};

// Final version with bug fixed:
StringClass &StringClass::operator=(const StringClass &rtside) {
    if (this == &rtside) {
        return *this;
    }
    else {
        capacity = rtside.capacity;
        length = rtside.length;
        delete [] a;
        a = new char[capacity];
        for (int i=0; i<length; i++) {
            a[i] = rtside.a[i];
            }
        return *this;
    }
}

