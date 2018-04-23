// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
class Solution {
public:
    bool search0(vector<int>& nums, int target) {
        int len = nums.size();
        int lo = 0, hi = len - 1;
        if (len == 0)
            return false;
        // 1. find minimum
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (nums[hi] > nums[mid]) {
                hi = mid;
            }
            else if (nums[hi] < nums[mid]) {
                lo = mid + 1;
            }
            else {
                hi--;
            }
        }
        // cout << lo << " " << hi << endl;
        // 2. find left-most minimum
        int shift = 0;
        cout << (lo - shift) % len << endl;
        while (nums[(lo + len - 1) % len] == nums[lo] && shift++ < len) {
            // cout << "shifted" << endl;
            lo = (lo + len - 1) % len;
        }
        // 3. binary search
        hi = (lo + len - 1);
        // cout << lo << " " << hi << endl;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int realMid = mid % len;
            if (target < nums[realMid]) {
                hi = mid - 1;
            }
            else if (target > nums[realMid]) {
                lo = mid + 1;
            }
            else
                return true;
        }
        return false;
    }
    
    // shortest solution from discussion
    bool search1(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
        
        while (lo <= hi) {
            int mid = (hi + lo) / 2;
            
            if (nums[mid] == target)
                return true;
            // since when lo < hi,
            // mid might equals to lo, and never equals to hi,
            // lo must increase at least 1 everytime.
            if (nums[mid] < nums[hi]) {
                if (target > nums[mid] && target <= nums[hi])
                    lo = mid + 1;
                else
                    hi = mid;
            }
            else if (nums[mid] > nums[hi]) {
                if (target <= nums[mid] && target >= nums[lo])
                    hi = mid;
                else
                    lo = mid + 1;
            }
            else {
                hi--;
            }
        }
        
        /*
         if make loop while (lo <= hi) instead of while (lo < hi)
         then we don't need the following code
        */
        
        // if (nums.size() > 0 && nums[lo] == target)
        //     return true;
        
        return false;
    }
    
    
    
    
    
    int bs(vector<int>& nums, int target, int lo, int hi) {
        // cout << lo << " " << hi << endl;
        if (lo > hi)
            return -1;
        int mid = (lo + hi) / 2;
        if (nums[mid] == target)
            return mid;
        
        
        if (nums[mid] < nums[hi]) { // right half is sorted
            if (nums[mid] < target && target <=nums[hi]) {
                return bs(nums, target, mid + 1, hi);
            }
            else {
                return bs(nums, target, lo, mid - 1);
            }
        }
        else if (nums[mid] > nums[hi]) { // left half is sorted
            if (nums[lo] <= target && target < nums[mid]) {
                return bs(nums, target , lo, mid - 1);
            }
            else {
                return bs(nums, target, mid + 1, hi);
            }
        }
        else { // nums[mid] == nums[hi]
            if (nums[mid] == nums[lo]) { // both half need to be searched
                int idx = bs(nums, target, lo, mid - 1);
                if (idx == -1)
                    idx = bs(nums, target, mid + 1, hi);
                return idx;
            }
            else { // search left half, because nums[mid] != target and right half are all duplicates
                return bs(nums, target, lo, mid - 1);
            }
        }
        return -1;
    }
    
    // recursive solution
    // from cc150 11.3, is more easy to implement
    bool search(vector<int>& nums, int target) {
        return bs(nums, target, 0, nums.size() - 1) != -1;
    }
};