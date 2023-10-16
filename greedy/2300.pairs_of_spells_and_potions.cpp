#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long threshold) {
        // sort potions
        sort(potions.begin(), potions.end());
        // binary search to find the index when the spell can surpass threshold with
        // needs to be inclusive 
        int m = potions.size();
        int n = spells.size();
        vector<int> result (n, 0);
        for (int i =0; i < n ; i++){
            int ind = bsearch(potions, 0, m-1, threshold, spells[i]);
            if (ind != -1) result[i] = m - ind;
        }
        return result;
    }
    int bsearch(vector<int>& potions, int s, int t, long long threshold, int spell){
        if (s == t){
            long long prod = (long long)spell * (long long)potions[s];
            if (prod < threshold) return -1;
            return s;
        }
        int mid = (s + t)/2;
        auto mid_potion = potions[mid];
        long long prod = (long long)spell * (long long)mid_potion;
        if (prod >= threshold){
            return bsearch(potions, s, mid, threshold, spell);
        }
        else{
            return bsearch(potions, mid + 1, t, threshold, spell);
        }
    }
};

int main(){
    Solution sol;
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2,3,4,5};
    long long threshold = 7;
    auto result = sol.successfulPairs(spells, potions, threshold);
    for (auto i : result) cout << i << " ";
    cout << endl;
    return 0;
}