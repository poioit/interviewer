/*
15. 3Sum
https://leetcode.com/problems/3sum/description/
*/



/*
[LeetCode] 3Sum Smaller 所有三数之和较小值
http://www.cnblogs.com/grandyang/p/5235086.html

611. Valid Triangle Number
https://leetcode.com/problems/valid-triangle-number/description/
// DFS or backtracking is very slow
// O(n^2) time solution exist, same as three sume smaller
*/
    // [2,2,3,4] -> 3
    // Same as 3 sum smaller
    // When looping fix the target to be compared of
    // e.g. the largest edge
    int triangleNumber(vector<int>& nums) {
        int total = 0;
        sort(nums.begin(), nums.end());
        int s = 0;
        // skip 0
        for (; s < nums.size() && nums[s] == 0; s++) {
        }
        // Fix the largest edges
        for (int k = s + 2; k < nums.size(); k++) {
            int i = 0, j = k - 1;
            // adjust the smaller two edges
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    total += (j - i);
                    j--;
                }
                else {
                    i++;
                }
            }
        }
        return total;
    }