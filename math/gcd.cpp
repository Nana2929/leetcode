#include<iostream>
#include<cassert>

int gcd(int a, int b){
    if (b == 0){return a;}
    return gcd(b, a%b);
}

// testing
int main(){
    std::cout << "Test 1" << std::endl;
    int a=50, b=15;
    std::cout << "gcd(" << a << ", " << b << ") = " << gcd(a, b) << std::endl;
    assert (gcd(a, b) == 5);
    std::cout << "Test 2" << std::endl;
    a=15, b=50;
    std::cout << "gcd(" << a << ", " << b << ") = " << gcd(a, b) << std::endl;
    assert (gcd(a, b) == 5);
    std::cout << "Test 3" << std::endl;
    a=15, b=29357;
    std::cout << "gcd(" << a << ", " << b << ") = " << gcd(a, b) << std::endl;
    assert (gcd(a, b) == 1);
    std::cout << "Test 4" << std::endl;
}