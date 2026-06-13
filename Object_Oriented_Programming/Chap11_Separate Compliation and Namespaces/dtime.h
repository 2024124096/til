#ifndef DTIME_H
#define DTIME_H

#include <iostream>
using std::istream;
using std::ostream;

namespace DTime {
    class DigitalTime {
    public:
        DigitalTime(int theHour, int theMinute);
        DigitalTime();

        int getHour() const;
        int getMinute() const;
        
        void advance(int minutesAdded);
        void advance(int hoursAdded, int minutesAdded);

        // istream, ostream은 <iostream>의 class type
            // private 멤버들에 접근해야 해서 friend로 선언함
        friend bool operator ==(const DigitalTime &time1,
                                const DigitalTime &time2);
        friend istream &operator >>(istream &ins, DigitalTime &theObject);
        friend ostream &operator <<(ostream &outs, const DigitalTime &theObject);
    
    private:
        int hour;
        int minute;
};

} // end namespace DTime

#endif // DTIME_H