#ifndef PFARRAYD_H
#define PFARRAYD_H

class PFArrayD {
    public:
        PFArrayD();
        PFArrayD(int size);
        PFArrayD(const PFArrayD &pfaObject);
        ~PFArrayD();
        
        int getNumberUsed() const;
        void addElement(double element);
        bool full() const;
        void emptyArray();
        
        double &operator [](int index) const;
        PFArrayD &operator =(const PFArrayD &rightSide);
    
    protected:
        double *a;
        int capacity;
        int used;
}; // end class PFArrayD

#endif // PFARRAYD_H