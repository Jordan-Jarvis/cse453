#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*************************************
 * ARRAY VULNERABILTY
 * 1. There must be an array and an array index variable
 * 2. The array index variable must be reachable through external input.
 * 3. There must not be bounds checking on the array index variable.
 ****************************************/
void arrayVulnerability(int index)
{
    cout << "\n The index location entered is: " << index << endl;
    int array[4];
    int authenticated = 0;
    array[index] = 1;
    cout << "\n  The user is ";
    if(!authenticated)
    {
        cout << "not ";
    }
    cout << "authenticated.\n";
    
}

/**************************************
 * ARRAY WORKING
 * Call arrayVulnerability() in a way that does
 * not yield unexpected behavior
 *************************************/
void arrayWorking()
{
   arrayVulnerability(2);
}

/**************************************
 * ARRAY EXPLOIT
 * 1. The attacker provides an array index value outside the expected range
 * 2. The attacker must be able to provide input or redirect
 *    existing input into the array at the index he provided
 * 3. The injected value must alter program state in a way
 *    that is desirable to the attacker
 *************************************/
void arrayExploit()
{
   arrayVulnerability(-1);
}

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

    /* Array Index */
    arrayWorking();
    arrayExploit();
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
