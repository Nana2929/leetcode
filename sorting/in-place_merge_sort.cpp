/*in-place Merge Sort
time complexity
O(n^2 * logn) -> bc this merge() needs O(n) steps for comparison and a nested O(n) steps for shifting
Space Complexity
O(1)
*/
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        MergeSort(nums, 0, nums.size()-1);
        return nums;

    }
    void MergeSort(vector<int>& nums, int low, int high){
        if (low < high){
            int mid=low + (high-low)/2;
            MergeSort(nums, low, mid);
            MergeSort(nums, mid+1, high);
            inPlaceMerge(nums, low, mid, high);
        }
    }
    // O(n^2) Merge (naive)
    void inPlaceMerge(vector<int>& nums, int low, int mid, int high){
        // nums:
        // low ~ mid, low2 ~ high, sorted subarrs respectively
        // O(n) merge the 2 subarrs
        int low2 = mid+1;
        if (low >= high){return;}
        if (nums[mid] < nums[low2]){return;}
        while (low <= mid && low2 <= high){
            // running index: low in subarr1
            // low2 in subarr2
            if (nums[low] < nums[low2]){low++; }
            else{
                // shift to left all by 1 element
                int index=low2;
                int value=nums[low2];
                while (index > low){
                    nums[index] = nums[index-1]; index--;
                }
                nums[index]=value;
                // update pointers
                // we want low ~ mid subarr to keep sorted
                low++; low2++; mid++;
            }
        }
    }
};