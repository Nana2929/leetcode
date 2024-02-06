/**
 * Nvidia | HackerRank Online Test | Minimum Step to Reduce Number to 0
Given a positive integer n, return the minimum number of step to reduce n to 0.
In one step, you can add or subtract a power of two (2^i, i >= 0).
https://leetcode.com/discuss/interview-question/2941097/NVIDIA-or-HackerRank-Online-Test-or-Minimum-Step-to-Reduce-Number-to-0
Observations:
1. If the n can be represented as 2^i (bit repr has only 1 set bit), then the min step is 1.
2.

Bit-wise takeway:
1. n & (-n) gives the rightmost set bit (= the lowes power of 2)
1110 (n=14)
& 0002 (-n, two's complement of n, is actually the flipped of n(0001) and add 1(0002))
-------
0010 (This is the repr of the rightmost set bit of n)
2. n & (n-1) removes the rightmost set bit
[False]
1110 (n=14)
& 1101 (n-1=13)
-------
1100 (14 is NOT a power of 2, so it has more than 1 set bit)
[True]
1000 (8)
& 0111 (7)
-------
0000 (8 is a power of 2, so it has only 1 set bit)

 **/

#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

int minStep(int n){
    // if n has one set bit,
    if ((n & (n-1)) == 0) return 1;
    // else, check the number of steps for n to reach its rightside 2 power neighbor and leftside 2 power neighbor
    // cout << "n & (-n) bit repr: " << bitset<8>(n & (-n)) << endl;
    // rightStep: adding the lowest power of two
    int rightStep = minStep(n + n & (-n));
    // leftStep: subtracting the lowest power of two
    int leftStep = minStep(n - n & (-n));
    // once we reach a certain power of 2, by either rightStep or leftStep, we can subtract all to 0 in 1 step. 
    return min(rightStep, leftStep) + 1;

}

int main(){
    int n = 27;
    cout << minStep(n) << endl;
    return 0;
}