#include <iostream>
#include "dtime.h"

// main.cpp에서만 쓰이는 readHour() 함수 먼저 정의. dtime.cpp에 있는 readHour()랑 다른 함수임!
    // 오직 사용자에게 시간 입력을 받기 위해 쓰이는 함수
    // C++ 규칙상 main에서 호출되는 함수는 main보다 위에 있어야 컴파일러가 알아챌 수 있으므로 먼저 정의하자

void readHour(int &theHour) {
    using std::cout;
    using std::cin;

    cout << "Let's play a time game.\n"
         << "Let's pretend the hour has just changed.\n"
         << "Enter the hour as a number (0 to 24): ";

    cin >> theHour;
}

int main() {
    using std::cout;
    using std::cin;
    using std::cerr;
    using std::endl;

    using DTime::DigitalTime;

    int theHour;
    readHour(theHour);
    DigitalTime clock(theHour, 0), oldClock;

    oldClock = clock;
    clock.advance(15);
    if (clock == oldClock) {
        cerr << "Something is wrong.\n";
    }

    cout << "You entered " << oldClock << endl;
    cout << "15 mins later the time will be " << clock << endl;

    clock.advance(2,15);
    cout << "2 hours and 15 mins after that\n"
         << "the time will be " << clock << endl;
    
    return 0;
}