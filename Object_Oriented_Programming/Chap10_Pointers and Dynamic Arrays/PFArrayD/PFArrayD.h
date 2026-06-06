class PFArrayD {
    public:
        PFArrayD(): capacity(50), used(0) { a = new double[capacity]; }
        PFArrayD(int size): capacity(size), used(0) { a = new double[capacity]; }
        PFArrayD(const PFArrayD &pfaObject); // copy constructor
        
        void addElement(double element);
        bool full() const { return (capacity == used); }
        void emptyArray() { used = 0; }
        
        double &operator [](int index);
        PFArrayD &operator =(const PFArrayD &rightSide); // overloaded assignment operator
        ~PFArrayD(); // destructor

        int getCapacity() const { return capacity; }
        int getUsed() const { return used; }
    
    private:
        double *a;
        int capacity;
        int used;
};