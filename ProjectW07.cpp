#include <iostream>
#include <iomanip>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

void one(long number);
void two(long number);
void pass() { cout << "You pass :)\n"; }
void fail() { cout << "You've failed :(\n"; }
const char * passMessage = ":)";
const char * failMessage = ":(";

/**********************************************
 * MAIN : The top of the callstack.
 **********************************************/
int main()
{
   char text[8] = "*MAIN**";
   long number = 123456;
   void (*pointerFunction)() = fail;
   const char * message = failMessage;

   // display the initial values of the local variables
   cout << "main() : " << (void *)main << endl;
   cout << "\ttext:             " << text              << endl;
   cout << "\tnumber:           " << number            << endl;
   cout << "\tmessage:          " << message           << endl;
   cout << "\tfunction pointer: ";
   pointerFunction();

   // call the other functions
   one(number + 111111);     // 234567

   // display the new values of the local variables
   cout << "main() - after\n";
   cout << "\ttext:             " << text              << endl;
   cout << "\tnumber:           " << number            << endl;
   cout << "\tmessage:          " << message           << endl;
   cout << "\tfunction pointer: ";
   pointerFunction();

   return 0;
}

/************************************************
 * CONVERT TO STRING
 * Convert the data from p into a human-readable string
 * by removing all the unprintable characters and replacing
 * them with a dot
 ***********************************************/
string displayCharArray(const char * p)
{
   string output;
   for (int i = 0; i < 8; i++)
       output += string(" ") + (p[i] >= ' ' && p[i] <= 'z' ? p[i] : '.');
   return output;
}

/**********************************************
 * ONE : The next item on the call stack
 **********************************************/
void one(long number)               // 234567
{
   char text[8] = "**ONE**";

   cout << "one() : " << (void *)one << endl;
   cout << "\tmessage: " << (void *)failMessage << endl;
   cout << "\tfail():  " << (void *)fail        << endl;

   two(number + 111111);    // 345678
}

/**********************************************
 * TWO : The bottom of the call stack
 **********************************************/
void two(long number)              // 345678
{
   // start your display of the stack from this point
   long bow = number + 111111;     // 456789
   char text[8] = "**TWO**";
   long * pLong = NULL;
   char * pChar = NULL;

   // header for our table. Use these setw() offsets in your table
   cout << '[' << setw(2) << 'i' << ']'
        << setw(15) << "address"
        << setw(20) << "hexadecimal"
        << setw(20) << "decimal"
        << setw(18) << "characters"
        << endl;
   cout << "----+"
        << "---------------+"
        << "-------------------+"
        << "-------------------+"
        << "-----------------+\n";
   for (long i = 34; i >= -10; i--)   // You may need to change 24 to another number
   {
      cout << std::left << setw(4) << i 
      << setw(17) << &bow + i << setw(20) 
      << *(&pLong + i) <<  setw(20) << *(&bow + i) << setw(5) << displayCharArray(&text[i * 8])  << endl;
      
      if (*(&bow + i) == 123456)
      {
         *(&bow + i) = 654321;
      }
     // displayCharArray(*(&pChar + i + bow));

      ////////////////////////////////////////////////
      // Insert code here to display the callstack
      
      //
      ////////////////////////////////////////////////
   }
   text[128] = 'C';
   text[129] = 'h';
   text[130] = 'a';
   text[131] = 'n';
   text[132] = 'g';
   text[133] = 'e';
   text[134] = 'd';
   //*(&bow + 122) = 654321;
   ////////////////////////////////////////////////
   // Insert code here to change the variables in main()
                                                                                
   // change text in main() to "*main**"

   // change number in main() to 654321
    long *newAddress = &number + 67;             // Assign pointer to number address
    *newAddress = 654321;                       // Assign address pointed at with new value
   // change pointerFunction in main() to point to pass

   // change message in main() to point to passMessage

   //
   ////////////////////////////////////////////////
}