#ifndef PFARRAYDBAK_H
#define PFARRAYDBAK_H

#include "PFArrayD.h"

class PFArrayDBak : public PFArrayD {
    public:
        PFArrayDBak();
        PFArrayDBak(int size);
        PFArrayDBak(const PFArrayDBak &Object);
        ~PFArrayDBak();

        // added member var and functions
        void backup();
        void restore();

        PFArrayDBak &operator =(const PFArrayDBak &rightSide);
    
    // 부모 클래스의 멤버를 자식이 쓸 수 있도록 Protect 접근자를 쓴 거기 때문에
        // 자식이 새로 추가한 멤버까지 꼭 protect일 필요는 없음
    private:
        double *b;
        int usedB;
}; // end class PFArrayDBak

#endif // PFARRAYDBAK_H