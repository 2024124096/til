#include <iostream>
#include <cstdlib>

using std::istream;
using std::ostream;
using std::cerr;
using std::endl;

#include "dtime.h"

namespace DTime {
    DigitalTime::DigitalTime(int theHour, int theMinute) {
    if (theHour < 0 || theHour > 23 || theMinute < 0 || theMinute > 59) {
        cerr << "Illegal argument to DigitalTime constructor." << endl;
        exit(1);
    }

    else {
        hour = theHour;
        minute = theMinute;
    }

    if (hour == 24) {
        hour = 0;
    } // 24:00 -> 0:00으로 정규화
}

DigitalTime::DigitalTime() {
    hour = 0;
    minute = 0;
}

int DigitalTime::getHour() const {
    return hour;
}

int DigitalTime::getMinute() const {
    return minute;
}

// Note differences from the textbook
void DigitalTime::advance(int minutesAdded) {
    int grossMinutes = minute + minutesAdded; // 분 총합
    minute = grossMinutes % 60; // 60 넘으면 나머지가 진짜 분
    int hourAdjustment = grossMinutes / 60; // 몇 시간 넘어갔는지?
    hour = (hour + hourAdjustment) % 24; // 24시 넘으면 0으로 wrap
}

void DigitalTime::advance(int hoursAdded, int minutesAdded) {
    hour = (hour + hoursAdded) % 24;
    advance(minutesAdded);
}

bool operator ==(const DigitalTime &time1, const DigitalTime &time2) {
    return (time1.hour == time2.hour && time1.minute == time2.minute);
}

ostream &operator <<(ostream &outs, const DigitalTime &theObject) {
    if (theObject.hour < 10) {
        outs << '0';
    }
    outs << theObject.hour << ':';
    
    if (theObject.minute < 10) {
        outs << '0';
    }
    outs << theObject.minute;

    return outs;
        // 반환하는 이유: 연쇄 출력 때문. cout을 반환해줘야 다음 << 에서 또 쓸 수 있음
}

istream &operator >>(istream &ins, DigitalTime &theObject) {
    // 실제 파싱은 readHour, readMinute에 위임
        // 이 프로그램에서 파싱 로직은 한자리/두자리 판별, 유효성 검사, int변환 등이 한 번에 쓰여져서 꽤 복잡함
        // 이걸 전부 이 오퍼레이터 안에 구현할 경우 너무 길고 지저분해지니까 역할을 나눈 것. 이 오버로딩에서는 흐름 제어만!
    readHour(ins, theObject.hour);
    readMinute(ins, theObject.minute);

    // 이것도 연쇄 입력 가능해야 하니까 반환
    return ins;
}
}

// helper fucntions
namespace {
    void readHour(istream &ins, int &theHour) {
    char c1, c2;
    ins >> c1 >> c2; // 문자 2개 읽기 (사용자가 11:15 입력하면 c1 = '1', c2 = '1')
    
    // isdigit() - <cctype> 헤더에 있는 함수로, 0~9 문자이면 T, 아니면 F
    if (!(isdigit(c1) && (isdigit(c2) || c2 == ':'))) {
        cerr << "Illegal hour input to readHour\n";
        exit(1);
    }

    if (isdigit(c1) && c2 == ':') {
        theHour = digitToInt(c1); // 한 자리 시간일 경우
    } else {
        // (isdigit(c1) && isdigit(c2)), 두 자리 시간일 경우
        theHour = digitToInt(c1)*10 + digitToInt(c2);
        ins >> c2; // discard ':' (버리기, 스트림에 11:15에서 11까지 읽었으니 하나 더 읽어서 버리는 것)
        if (c2 != ':') {
            cerr << "Illegal hour input to readHour\n";
            exit(1);
        }
    }

    // readHour는 생성자를 안 거치고 theObject.hour에 직접 값을 쓰니까 정규화 한 번 더 해줌
    if (theHour == 24) {
        theHour = 0;
    }

    if (theHour < 0 || theHour > 23) {
        cerr << "Illegal hour input to readHour\n";
        exit(1);
    }
}

void readMinute(istream &ins, int &theMinute) {
    char c1, c2;
    ins >> c1 >> c2;
    if (!(isdigit(c1) && isdigit(c2))) {
        cerr << "Illegal minute input to readMinute\n";
        exit(1);
    }

    theMinute = digitToInt(c1)*10 + digitToInt(c2);
    if (theMinute < 0 || theMinute > 59) {
        cerr << "Illegal minute input to readMinute\n";
        exit(1);
    }
}

int digitToInt(char c) {
    // ASCII 코드 상에서 숫자 문자들은 연속으로 배열되어 있기 때문에,
        // c를 int로 바꾸더라도 기준점인 0에 해당하는 값을 빼줘야함
    return static_cast<int> (c)
        - static_cast<int> ('0');
}
} // end unnamed namespace