#include <iostream>
using namespace std;

#include "PFArrayD.h"

int main() {
    cout << "This program tests the class PFArrayD.\n";
    char ans;
    do {
        testPFArrayD();
        cout << "Test again? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}

void testPFArrayD() {
    int cap;
    cout << "Enter the capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);

    cout << "Enter up to " << cap << " nonnegative numbers.\n"
         << "Place a negative number at the end.\n";
    double next;
    cin >> next;
    while (next >= 0 && !temp.full()) {
        temp.addElement(next);
        cin >> next;
    }

    int count = temp.getUsed();
    cout << "You entered the following "
         << count << " numbers:\n";
    for (int index = 0; index < count; index++) {
        cout << temp[index] << " ";
    }

    cout << endl;

    // 루프를 끝내기 위한 신호용 특수 값
        // 이 프로그램 설정상 음수가 들어오면 룹이 종료되는데,
        // 다음 값인 음수는 배열에 저장하지 않고 마커로 쓴 다음 루프를 탈출함
    cout << "(plus a sentinel value of " << next << ".)\n";
}