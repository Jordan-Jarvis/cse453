#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*************************************
 * ARRAY VULNERABILITY
 * 1. There must be an array and an array index variable
 * 2. The array index variable must be reachable through external input.
 * 3. There must not be bounds checking on the array index variable.
 ****************************************/
void arrayVulnerability(int index)
{
    cout << "\nThe array size is 4.";
    cout << "\nThe index location entered is: " << index << endl;
    int array[4];
    int authenticated = 0;
    array[index] = 1;
    cout << "The user is ";
    if(!authenticated)
    {
        cout << "not ";
    }
    cout << "authenticated.\n\n";

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
   arrayVulnerability(7);
}

/*********************************************
 * Pointer Subterfuge
 * ******************************************/
void pointerSubterfuge(int bufindex, long addtobuf) {
    long buffer[1];
    char * p1 = "Computer";
    char * p2 = "Security"; // the top secret password
    
    cout << "The p1 pointer points to: " << p1 << endl;
    cout << "The buffer index " << bufindex
         << " contains: " << buffer[bufindex] << endl;
    
    buffer[bufindex] = buffer[bufindex] + addtobuf; // actually referencing the pointer 'p1'
    
    cout << "The p1 pointer Now points to: " << p1 << endl;
    cout << "The buffer index " << bufindex
         << " now contains: " << buffer[bufindex] << endl;
}

/**************************************
 * POINTER SUBTERFUGE WORKING
 *************************************/
void pointerWorking()
{
   pointerSubterfuge(0, 4);
}

/**************************************
 * POINTER SUBTERFUGE EXPLOIT
 **************************************/
void pointerExploit()
{
   pointerSubterfuge(2, 9);
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

/*****************************
*ARC Injection function
*1. There must be a function pointer used in the code.
*2. Through some vulnerability, there must be a way for user input to overwrite the function pointer.
*3. After the memory is overwritten, the function pointer must be dereferenced.
 ******************************/
void arcVulnerability(long value){
    void (*f)();
    cout << "The function pointer 'void (*f)()' has been created."<<endl;
    
    long buffer[4];
    
    if (value <= 2147483647 && value > -2147483647) {
        buffer[0] = value;
        cout << "The value in the buffer is " << buffer[0] << endl;
        
    } else {
        cout << "The function pointer was overwritten." << endl;
    }
}

void arcWorking() {
    arcVulnerability(755);
}

void arcExploit() {
    arcVulnerability(2500000000000);
}


/*****************************************
 *Stack Smashing - INCOMPLETE
 *1. There must be a buffer on the stack.
 *2. The buffer must be reachable from an external input.
 *3. The mechanism to fill the buffer from the external input must not correctlly check for the  buffer size.
 *4. THe buffer must be overrun.
 *******************************************/

void stackVulnerability(string words) {
    
    char phrase[5];
    /* Commenting out to be able to compile
    strcpy(<#char *__dst#>, <#const char *__src#>)
    
    if () {
        cout << "The stack isn't vulnerable." << endl;
        cout << phrase[0] << endl;
    } else {
        cout << "The stack is vulnerable" << endl;
        cout << phrase[0] << endl;

    }
    */
}

void stackWorking() 
{
    //char *name = "Fort";
    //stackVulnerability(name);
}

void stackExploit() {
    //char *name = "Mackenzie";
    //stackVulnerability(name);
}


void unicodeVulnerability(short unicodeText[], int size)
{

    for(int i = 0; i < size - 1; i++)
    {
        unicodeText[i] = 0; // set the values to 0
    }
        int pass = 1;
}

void unicodeExploit()
{
    const int n = 2;
    short unicodeText[n];
    int pass = 1;
    cout << "\nBefore Unicode-ANSI Exploit the pass variable = " << pass << endl;
    unicodeVulnerability(unicodeText, sizeof(unicodeText));
    cout << "After Unicode-ANSI Exploit the pass variable = " << pass << endl;

}

void unicodeWorking()
{
    const int n = 2;
    short unicodeText[n];
    int pass = 1;
    cout << "\nVulnerability is fixed, pass = " << pass << " before running." << endl;
    unicodeVulnerability(unicodeText, n);
    cout << "Vulnerability is fixed, pass = " << pass << " after running as well." << endl;

}

/*************************************
 * HEAP SPRAYING
 * 1. There must be two adjacent heap buffers.
 * 2. The first buffer must be reachable through external input.
 * 3. The mechanism to fill the buffer from the external input must not
      correctly check for the buffer size.
 * 4. The second buffer must be released before the first.
 * 5. The first buffer must be overrun (extend beyond the intended limits of
    the array).
 ****************************************/
void heapVulnerability()//char &text)
{
    char * buffer1 = new char[4]; // requires two buffers on the heap
    char * buffer2 = new char[4];
    bool smashing = true;

    strcpy(buffer1, "jojo");
    strcpy(buffer2, "nono");
    assert(buffer1 < buffer2);

    //delete [] buffer2; // need to delete second buffer first

    for (int i = 4; i < 5; i++)
    {
        buffer1[i] = 't';
    }
    delete [] buffer2;
    cout << "Buffer: " << buffer1 << endl;

    delete [] buffer1;
}

/**************************************
 * HEAP WORKING
 * heapWorking() that calls heapVulnerability()
 * with non-malicious input.
 *************************************/
void heapWorking()
{
    char workingText[4] = "gun";
   // heapVulnerability(workingText); // non malicious input
}

/**************************************
 * HEAP EXPLOIT
 * heapVulnerability() must be vulnerable to heap
 * smashing but you will only be required to 
 * demonstrate heap spraying.
 *************************************/
void heapExploit()
{
    char errorText[30] = "More than 10 characters";
    //heapVulnerability(*errorText); // be vulnerable to heap smashing
}




// Driver code
int main()
{
    char input;
    while (true)
    {
        cout << "\n\nPlease select an option and press enter.\n";
        cout << " 1 - Array Vulnerability\n";
        cout << " 2 - Pointer Subterfuge\n";
        cout << " 3 - ARC Injection\n";
        cout << " 4 - VTable Spraying\n";
        cout << " 5 - Stack Smashing\n";
        cout << " 6 - Heap Spraying\n";
        cout << " 7 - Integer Overflow\n";
        cout << " 8 - ANSI-Unicode Conversion\n";
        cout << " 9 - Exit\n";
        cout << " Input:";
        cin >> input;
        switch (input)
        {
            case '1':
                cout << "\n----------------------------------";
                cout << "\n--------Array Vulnerability-------";
                cout << "\n----------------------------------\n";
                /* Array Index */
                arrayWorking();
                arrayExploit();
                cout << "If the user is authenticated then the exploit worked.";
                break;
            case '2':
                cout << "\n----------------------------------";
                cout << "\n-Pointer Subterfuge Vulnerability-";
                cout << "\n----------------------------------\n";
                /* Pointer Subterfuge */
                cout << "This is how a normal pointer works: " << endl; 
                pointerWorking();
                cout << endl;
                cout << "This is how a pointer subterfuge exploit works: " << endl;
                pointerExploit();
                break;
            case '3':
                cout << "\n----------------------------------";
                cout << "\n--------ARC Vulnerability---------";
                cout << "\n----------------------------------\n";
                arcWorking();
                arcExploit();
                break;

            case '4':
                cout << "\n----------------------------------";
                cout << "\n--------V_Table Spraying----------";
                cout << "\n----------------------------------\n";
                // allocate memory on the heap for an object of class 'B',
                // then point to class A with it. The virtual function in
                // class 'A' will then be pointed to from that object. The
                // function will print 'case one' if the spraying is successful.
               // A* b = new B();
               // b->foo();
                break;
            case '5':
                cout << "\n----------------------------------";
                cout << "\n--------Stack Smashing------------";
                cout << "\n----------------------------------\n";
                stackWorking();
                stackExploit();
                break;
            case '6':
                cout << "\n----------------------------------";
                cout << "\n--------Heap Vulnerability--------";
                cout << "\n----------------------------------\n";
                /* Heap Index */
                heapWorking();
                heapExploit();
                heapVulnerability();
                break;
            case '7':
                cout << "\n----------------------------------";
                cout << "\n--------Integer Overflow----------";
                cout << "\n----------------------------------\n";
                //int *res = new int[(sizeof(int))];
                //int x = 2147483640;
                //int y = 10;
                // Print integer overflow function return value: -1 = overflow, 0 = no overflow
                //cout<<addOvf(res, x, y);
                break;
            case '8':
                cout << "\n----------------------------------";
                cout << "\n--------Unicode_ANSI--------------";
                cout << "\n----------------------------------\n";
                unicodeExploit();
                unicodeWorking();
                break;
            case '9':
                return 0;
            default:
                cout << "Invalid input.\n";
        }

    }
    
    return 0;
}
