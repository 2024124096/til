#include <iostream>
#include "Money.h"
using namespace std;

int main() {
    Money yourAmount, myAmount(10, 9);
    cout << "Enter an amount of money: ";
    yourAmount.input();
    cout << "Your amount is: ";
    yourAmount.output();
    cout << endl;

    cout << "My amount is: ";
    myAmount.output();
    cout << endl;

    if (yourAmount == myAmount) {
        cout << "We have the same amounts.\n";
    }
    else {
        cout << "One of us is richer.\n";
    }

    Money ourAmount = yourAmount + myAmount;
    yourAmount.output(); cout << " + "; myAmount.output();
    cout << " equals "; ourAmount.output(); cout << endl;

    Money diffAmount = yourAmount - myAmount;
    yourAmount.output(); cout << " - "; myAmount.output();
    cout << " equals "; diffAmount.output(); cout << endl;

    return 0;
}