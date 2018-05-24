//https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        while (true) {
            int p = partition(nums, l, r);
            if (p == k-1) {
                return nums[p];
            }
            else if (p > k-1) {
                r = p-1;
            }
            else {
                l = p+1;
            }
        }
        return 0;
    }
    
    // put larger in left half
    int partition(vector<int>& nums, int l, int r) {
        swap(nums[l], nums[(l+r)/2]); // pick mid as pivot
        int pivot = nums[l];
        int s = l, e = r;
        while (s < e) {
            if (nums[e] > pivot) {
                nums[s] = nums[e];
                nums[e] = nums[s+1];
                s++;
            }
            else {
                e--;
            }
        }
        nums[s] = pivot;
        return s;
    }
};