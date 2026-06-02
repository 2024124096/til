#include <iostream>
using namespace std;

typedef int* IntPointer;
// 기존 타입에 새 이름(별칭)을 붙이는 문법
    // 이렇게 해두면 이제 IntPointer가 int*와 동일한 의미가 됨.
    // int* p1, p2;  --> p1만 포인터, p2는 그냥 int! 였는데,
    // IntPointer p1, p2; --> p1, p2 둘 다 포인터가 됨. 실수 확률 감소

void sneaky(IntPointer temp);

int main() {
    IntPointer p;
    p = new int;
    *p = 77;
    cout << "Before call to function *p == "
         << *p << endl;
    
    sneaky(p);

    cout << "After call to function *p == "
         << *p << endl;
    
    return 0;
}

void sneakey (IntPointer temp) {
    *temp = 99;
    cout << "Inside function call *temp == "
         << *temp << endl;
}


