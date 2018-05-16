//https://leetcode.com/problems/wiggle-sort/description/
class Solution {
public:
    void wiggleSort0(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i+=2) {
            if (i + 1 < nums.size())
                swap(nums[i], nums[i+1]);
        }
        
    }
    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (i % 2 == 0) {
                if (nums[i + 1] < nums[i])
                    swap(nums[i], nums[i+1]);
            }
            else {
                if (nums[i + 1] > nums[i])
                    swap(nums[i], nums[i+1]);
            }
        }
    }
};