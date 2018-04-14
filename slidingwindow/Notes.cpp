/* ============================================================================
https://leetcode.com/problems/minimum-window-substring/description/
76. Minimum Window Substring
Given a string S and a string T, find the minimum window in S which
will contain all the characters in T in complexity O(n).
============================================================================ */

    string minWindow(string s, string t) {
        int map[128] = {0};
        for (char c : t)
            ++map[c];
        int quota = t.size();
        int start = 0, len = INT_MAX;
        int head = 0;
        for (int end = 0; end < s.size(); ++end) {
            if(map[s[end]] > 0) // is char in t
                --quota;
            --map[s[end]]; // this will also minus 1 for char not in t
            while (quota == 0) { // all char in t are found
                if (map[s[start]] >= 0) { // this is a char in t, is a valid result
                    if (end - start + 1 < len) { // if shorter, record it
                        head = start;
                        len = end - start + 1;
                    }
                    ++quota; // after record, put current char back into quota
                }
                ++map[s[start]];
                ++start;
            }
        }
        return len == INT_MAX ? "" : s.substr(head, len);
    }

/* ============================================================================
https://leetcode.com/problems/minimum-size-subarray-sum/description/
209. Minimum Size Subarray Sum
Given an array of n positive integers and a positive integer s, find
the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
============================================================================ */
    int minSubArrayLen(int s, vector<int>& nums) {
        int rst = INT_MAX;
        int sum = 0;
        int start = 0;
        int end = 0;
        while (end < nums.size()) {
            sum += nums[end];
            ++end;
            while (sum - nums[start] >= s) {
                sum -= nums[start];
                ++start;
            }
            if (sum >= s)
                rst = min(rst, end - start);
        }
        
        return rst == INT_MAX ? 0 : rst;
    }