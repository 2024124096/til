#include <iostream>
using namespace std;

typedef int* IntPtr;

void fillArray(int a[], int size);
int search(int a[], int size, int target);

int main() {
    cout << "This program searches a list of numbers.\n";

    int arraySize;
    cout << "How many numbers will be on the list? ";
    cin >> arraySize;
    IntPtr a;
    a = new int[arraySize];
    
    fillArray(a, arraySize);

    int target;
    cout << "Enter a value to reach for: ";
    cin >> target;
    int location = search(a, arraySize, target);
    if (location == -1) {
        cout << target << " is not in the array.\n";
    }

    else {
        cout << target << " is element " << location << " in the array.\n";
    }

    delete [] a; // a가 가리키는 힙에 동적으로 할당된 배열 전체 삭제
    return 0;
}

void fillArray(int a[], int size) {
    cout << "Enter " << size << " integers.\n";
    for (int index = 0; index < size; index++) {
        cin >> a[index];
    }
}

int search(int a[], int size, int target) {
    int index = 0;
    while ((a[index] != target) && (index < size))
        index++;
    if (index == size) {
        // then the target is not in a
        index = -1;
    }

    return index;
}

