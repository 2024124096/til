#include <iostream>
using namespace std;

class C {
    public:
        C() : name(new string("Unnamed")) {
            cout << "Constructor called for " << *name << endl;
        }

        C(const string &n) : name(new string(n)) {
            cout << "Constructor called for " << *name << endl;
        }

        C(const C &other) : name(new string(*other.name)) {
            cout << "Copy constructor called for " << *name << endl;
        }

        ~C() {
            cout << "Destructor called for " << *name << endl;
            delete name;
        }

        string *getName() const { return name; }
        
        C &operator=(const C &other) {
            if (this != &other) {
                delete name;
                name = new string(*other.name);
                cout << "Copy assignment operator called for " << *name << endl;
            }
            return *this;
        }
    
    private:
        string *name;
};

C f(C c) {
    cout << "Inside function f, received object with name: "
         << *(c.getName()) << endl;
    C a("local");
    cout << "Returning from function f, local object name: "
         << *(a.getName()) << endl;
    return a;
}

int main() {
    C c1("Main");
    cout << "Calling function f with c1 ..." << endl;

    C c2 = f(c1);
    cout << "In main, c2's name: "
         << *(c2.getName()) << endl;
    
    c2 = c1;
    cout << "After assignment, c2's name ..."
         << *(c2.getName()) << endl;

    return 0;
}