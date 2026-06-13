#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "PFArrayDBak.h"

int main() {
    cout << "This program tests the class PFArrayDBak.\n";
    char ans;
    do {
        testPFArrayDBak();
        cout << "Test again? (y/n) ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}

void testPFArrayDBak() {
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayDBak a(cap);

    cout << "Enter up to " << cap << " nonnegative numbers.\n"
         << "Place a negative number at the end.\n";
    
    double next;
    cin >> next;
    while (next >= 0 && (!a.full())) {
        a.addElement(next);
        cin >> next;
    }

    if (next >= 0) {
        cout << "Could not read all numbers.\n";
        while (next >= 0) { // Clear the unread input
            cin >> next;
        }
    }

    int count = a.getNumberUsed();
    cout << "The following " << count << " numbers read and stored:\n";
    for (int i=0; i<count; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Backing up array.\n";
    a.backup();
    cout << "Emptying array.\n";
    a.emptyArray();
        // 백업이 제대로 되었는지 확인하기 위해 배열을 비움

    cout << a.getNumberUsed() << " numbers are now stroed in the array.\n";
    cout << "Restoring array.\n";
    a.restore();
    count = a.getNumberUsed();
    cout << "The following " << count << " numbers are now stored:\n";
    for (int i=0; i<count; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}