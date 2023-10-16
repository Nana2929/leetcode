#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

// link: https://leetcode.com/problems/boats-to-save-people/description/
// greedy + 2 pointers
// Time: O(NlogN), where N is the length of people (sort)
// Space: O(logN), in-place sorting in cpp uses a mix of quicksort, heapsort, and insertion sort, with worst case O(logN) space complexity
class Solution {
public:
    int numRescueBoats(vector<int>& ppl, int limit) {
        // thanks for the intuition in discussion
        sort(ppl.begin(), ppl.end());
        int i = 0;
        for (i; i < ppl.size(); i++){
            if (ppl[i] >= limit){
                break;
            }
        }
        cout << i << endl;
        int n_boats = ppl.size() - i; // at least this number of boats are needed
        // now 2 pointers
        int l = 0;
        int r = i-1;
        while (l < r){
            if (ppl[l] + ppl[r] <= limit){
                n_boats ++;
                l++; r--;
            }
            else{
                n_boats ++;
                r --;
            }

        }
        if (l == r){
            n_boats ++;
        }
        return n_boats;
    }
};

int main(){
    Solution sol;
    vector<int> ppl = {3,2,2,1};
    int limit = 3;
    cout << sol.numRescueBoats(ppl, limit) << endl;
    return 0;
}