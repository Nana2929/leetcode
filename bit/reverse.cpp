
#include <stdio.h>
#include <bitset>
#include <iostream>
using namespace std;

unsigned int reverse(unsigned int a){
    unsigned int res = 0;
    while (a){
        res = (res << 1) + (a&(0x01));
        a = a >> 1;
    }
    return res;
}

int main(){
    unsigned int a = 0b11110000;
    unsigned int b = reverse(a);
    printf("%d\n", b);
    return 0;
}