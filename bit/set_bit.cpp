

// write the following code
//     a. set Bit3 of int a
//     b. clear Bit3 of int a

#include <iostream>
using namespace std;



int main()
{
    int a = 10;
    a = a | (1 << 3); //1010
    cout << a << endl; // 1010 (0-indexed) -> 10
    int b = 10;
    b = b & ~(1 << 3); // 1010
    cout << b << endl; // 0010 -> 2

    return 0;

}