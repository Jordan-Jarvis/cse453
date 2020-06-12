#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*******************************************
 * If there is no overflow, the function
 * places the sum of a+b in “result” and
 * returns 0, otherwise it returns -1.
 *******************************************/
int addOvf(int* result, int a, int b)
{
    *result = a + b;
    if(a > 0 && b > 0 && *result < 0)
        return -1;
    if(a < 0 && b < 0 && *result > 0)
        return -1;
    return 0;
}

/******************************************
 * V-table setup. A class with a virtual
 * function that gets overwritten by another
 * class object pointing to the initial class.
 ******************************************/

class A {
public:
    virtual void foo() = 0;
};

class B : public A {
private:
    void (B::*_f)();

public:
    B() { chooseOne(); }

    void caseOne() {
        cout << "case one" << endl;
    }

    void chooseOne() { _f = &B::caseOne; }

    void foo() {
        (this->*_f)();
    }
};

void arcVulnerability(){
    int numbers[5];
    void (* conversion)() = arcVulnerability;
    
    cout << "Enter a 5 digit number: ";
    cin >> numbers[5];
    
    conversion();
}

// Driver code
int main()
{

    /* INTEGER OVERFLOW */

    int *res = new int[(sizeof(int))];
    int x = 2147483640;
    int y = 10;

    // Print integer overflow function return value: -1 = overflow, 0 = no overflow
    cout<<addOvf(res, x, y);


    /* V_TABLE SPRAYING */

    // allocate memory on the heap for an object of class 'B',
    // then point to class A with it. The virtual function in
    // class 'A' will then be pointed to from that object. The
    // function will print 'case one' if the spraying is successful.
    A* b = new B();
    b->foo();

    return 0;
}
