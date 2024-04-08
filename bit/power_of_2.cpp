#include <iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && ((n & (n-1))==0);
        // https://en.cppreference.com/w/cpp/language/operator_precedence
    }
};


int main(){
    Solution s;
    int n = 16;
    cout << s.isPowerOfTwo(n) << endl;
    return 0;
}