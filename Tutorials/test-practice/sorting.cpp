
/**
* Apstract Class that contains the template method.
* This class defines a template method for a sort.
*/
class Sorting {
public:
    void sort() { //template method
        printArray();
        processArray();
    }
    void printArray(); //invariant method
    virtual bool compare(int a, int b) = 0; //variant method
    virtual void processArray(); //optional method
};

/**
* Concrete class that implements the variant methods for the Sorting class.
*/
class AscendingSort : public Sorting {
public:
    bool compare(int a, int b) override {
        return (a - b) < 0;
    }
};

/**
* Concrete class that implements the variant methods for the Sorting class.
*/
class DscendingSort : public Sorting {
public:
    bool compare(int a, int b) override {
        return (b - a) < 0;
    }
};
