//https://leetcode.com/problems/remove-duplicate-letters/description/

class Solution {
public:
    // greedy
    string removeDuplicateLetters(string s) {
        
        vector<int> count(128, 0);
        vector<bool> included(128, false);
        
        // each char's count
        for (char c : s) {
            count[c]++;
        }
        
        string rst;
        for (char c : s) {
            count[c]--; // spend 1 of c
            
            if (included[c]) // already in the answer
                continue;
            
            // if the last char in current answer is smaller than the current char, (lexicographical order)
            // and it still appears later (count[rst.back()] > 0),
            // keep popping it, leave it to be chosen later since there's still quota.
            while (rst.size() > 0 && c < rst.back() && count[rst.back()] > 0) {
                included[rst.back()] = false;
                rst.pop_back();
            }
            
            // push current char
            rst.push_back(c);
            included[c] = true;
        }
        
        return rst;
    }
};