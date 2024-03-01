
#include<map>
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto x: nums){
            if (!m.count(x)){m[x]=1;}
            else if (m[x]==1){m[x]++;}
            else{return false;}

        }
        return true;

    }
};

int main(){
    Solution s;
    vector<int> nums = {1,1,1,1};
    bool res = s.isPossibleToSplit(nums);
    cout << res << endl; // 1
    return 0;
}