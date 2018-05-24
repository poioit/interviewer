// https://leetcode.com/problems/create-maximum-number/description/

class Solution {
public:
    // tooooooooo hard!
    // refer to: https://leetcode.com/problems/create-maximum-number/discuss/77285/Share-my-greedy-solution
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> rst;
        int n = nums1.size();
        int m = nums2.size();
        for (int i = 0; i <= k && i <= n; ++i) {
            if (i <= n && k-i <= m) {
                vector<int> max1 = pickMax(nums1, i);
                vector<int> max2 = pickMax(nums2, k-i);
                vector<int> cand = merge(max1, max2, k);
                if (greater(cand, 0, rst, 0)) {
                    rst = cand;
                }
            }
        }

        return rst;
    }
    
    vector<int> merge(vector<int> &num1, vector<int> &num2, int k) {
        vector<int> rst;
        for (int i = 0, j = 0; rst.size() < k; ) {
            if (greater(num1, i, num2, j)) {
                rst.push_back(num1[i]);
                i++;
            }
            else {
                rst.push_back(num2[j]);
                j++;
            }
        }
        return rst;
    }
    
    bool greater(vector<int> &num1, int i, vector<int> &num2, int j) {
        while (i < num1.size() && j < num2.size() && num1[i] == num2[j]) {
            i++;
            j++;
        }
        if (j == num2.size()) { // num2 is shorter
            return true;
        }
        else if (i < num1.size() /*&& j < num2.size() */&& num1[i] > num2[j]) {
            return true;
        }
        return false;
    }
    
    vector<int> pickMax(vector<int> &nums, int k) {
        int len = nums.size();
        vector<int> rst;
        for (int i = 0; i < len; i++) {
            // len-i + nums.size() > k means there's still buffer, "the rest of input + the numbers already in rst" > k,
            // so numbers can be popped out, and let bigger numbers in
            while (len-i + rst.size() > k && rst.size() > 0 && rst.back() < nums[i]) {
                rst.pop_back();
            }
            if (rst.size() < k)
                rst.push_back(nums[i]);
        }
        return rst;
    }
};