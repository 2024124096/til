#include <iostream>
using namespace std;

    void f(int v, int *p) {
        cout << "Inside function f, before modification: " << endl
             << "v, *p: " << v << ", " << *p << endl;
        v = 10;
        *p = 20;
        cout << "Inside function f, after modification: " << endl
             << "v, *p: " << v << ", " << *p << endl;             
    }

    void f(int v, int *p, int &r) {
        cout << "Inside function f: " << endl
             << "Address of v: " << &v << endl
             << "Value of p: " << p << endl
             << "Address of r: " << &r << endl;
    }

int main () {
    int x = 10;
    int *y = &x;
    int &z = x;

    cout << "In main:" << endl
         << "Address of x: " << &x << endl
         << "Value of y: " << y << endl
         << "Address of z: " << &z << endl;
    
    f(x, y, z);
    
    return 0;
}



