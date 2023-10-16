#include <iostream>
#include <vector>
using namespace std;

// Description: https://leetcode.com/problems/binary-search/

class Solution
{
public:
    int search(vector<int>& nums, int target) {
        return bsearch(nums, target, 0, nums.size()-1);
    }
    int bsearch(vector<int>& nums, int target, int s, int t){
        if (s > t){
            return -1;
        }
        int mid = (s + t)/2; //flooring 
        int val = nums[mid];
        if (val == target){
            return mid;
        }
        else if (val > target){
            return bsearch(nums, target, s, mid-1);
        }
        else {
            return bsearch(nums, target, mid+1, t);
        }
    }
};

int main(){
    Solution s;
    cout << "704. Binary Search" << endl;
    cout << "Link: https://leetcode.com/problems/binary-search/" << endl;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    cout << s.search(nums, target) << endl; // 4


    vector<int> nums2 = {-1,0,3,5,9,12};
    int target2 = 2;
    cout << s.search(nums2, target2) << endl; // -1
    return 0;
}
