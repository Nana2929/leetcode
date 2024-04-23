#include<vector>
#include<iostream>
using namespace std;


/*
Triboonacci Sequence
T0 = 0, T1 = 1, T2 = 1
Tn = Tn-1 + Tn-2 + Tn-3
Input: n (0<=n<=37)
1. Normal DP
    Time Complexity: O(n)
2. Matrix Exponentiation O(logn)
    (0) Observe that we can solve the problem by multiplying a series of (same) matrices.
    We have 3 equations:
            f(n)   = f(n-1) + f(n-2) + f(n-3)
            f(n-1) = f(n-1)
            f(n-2) =          f(n-2)

    By turning them into matrix realtion. we get:
            | f(n)   |     | 1 1 1 |     | f(n-1) |
            | f(n-1) |  =  | 1 0 0 |  *  | f(n-2) |
            | f(n-2) |     | 0 1 0 |     | f(n-3) |

    Since we can compute an matrix exponent by O(log(n)), Simplify the relation into exponents
            | f(n)   |     | 1 1 1 |^(n-2)     | f(2) |
            | f(n-1) |  =  | 1 0 0 |       *   | f(1) |
            | f(n-2) |     | 0 1 0 |           | f(0) |

    (1) Why logn?
    For a matrix of size k×k, the multiplication complexity is O(k^3) under the standard algorithm (can be optimized to O(k^2.81) using the Strassen algorithm).
    Regardless of optimization, the matrix we deal with is size 3 x 3, hence k=3, and the complexity is O(3^3) = O(27) = O(1).
    | 1 1 1 |
    | 1 0 0 |
    | 0 1 0 |
    And then for Matrix Exponentiation, we can make use of `Exponentiation by Squaring` (https://en.wikipedia.org/wiki/Exponentiation_by_squaring#Computational_complexity),
    that is, when we need to get M^n, we get Power(M, n/2) and then multiply the result by itself. This is a recurrence relation of:
    T(n) = T(n/2) + O(1) = O(logn)
    In summary, the overall complexity is O(k^3 * logn), where k is the size of the matrix and n is the exponent.
    = O(1 * logn) = O(logn).
    (3) Back to the question, we can solve Tribonacci in O(logn) time complexity. This is a common technique in CP.

    reference: https://leetcode.com/problems/n-th-tribonacci-number/solutions/347604/c-o-k-3log-n-solution-k-3-matrix-exponentiation

*/
class Solution1 {
    private:
    vector<int> dp;
public:
    Solution1() {
        dp.resize(38);
        dp[0]=0;dp[1]=1;dp[2]=1;}

    int tribonacci(int n) {
        if (n<=2){return dp[n];}
        if (dp[n]!=0){return dp[n];}
        for (int x=3;x<=n;x++){
            dp[x] = dp[x-1] + dp[x-2] + dp[x-3];
        }
        return dp[n];
    }
};

class Solution2 {
public:
    vector<vector<int>> MatMul(vector<vector<int>>& M1, vector<vector<int>>& M2){
        // mat1: (x, y); mat2: (y, z)
        vector<vector<int>> ans(M1.size(), vector<int>(M1[0].size(), 0));
        for (int i =0; i<M1.size();i++){
            for (int j=0;j<M2[0].size();j++){
                for (int k = 0; k<M1[0].size();k++){
                    ans[i][j] += M1[i][k] * M2[k][j];
                }
            }
        }
        return ans;
    }
    vector<vector<int>> Power(vector<vector<int>> M, int n){
        // Assume: M is a squared matrix
        // return M^n

        if (n==0){
            // make identity matrix
            vector<vector<int>> Iden(M.size(), vector<int>(M[0].size()));
            for (int i = 0; i< M.size();i++){Iden[i][i]=1;}
            return Iden;}
        else if (n==1){return M;}
        else{
            vector<vector<int>> Half = Power(M, n/2); // This recurrence relation is O(logn)
            vector<vector<int>> All = MatMul(Half, Half);
            if (n%2==1){All = MatMul(All, M);}
            return All;
        }

    }
    int tribonacci(int n) {
        if (n==0){return 0;}
        if (n<=2){return 1;}
        vector<vector<int>> base = {
            {1}, // F2
            {1}, // F1
            {0}}; // F0
        // recurrence relation
        vector<vector<int>> rec = {
            {1,1,1},
            {1,0,0},
            {0,1,0}};
        vector<vector<int>> power = Power(rec, n-2);
        vector<vector<int>> x = MatMul(power, base);
        return x[0][0];

    }
};