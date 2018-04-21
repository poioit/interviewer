
//https://leetcode.com/problems/interleaving-string/description/

class Solution {
public:
    // like a traveral problem
    // move right use letter in s2
    // move down: use letter in s1
    //    d b b c a (s2)
    // *  - - - - -
    // a |          |
    // a |          |
    // b |          |
    // c |          |
    // c |          |
    //    - - - - - *
    //(s1)
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
        
        for (int i = 0; i <= s1.size(); i++) {
            for (int j = 0; j <= s2.size(); j++) {
                // use 0 letters in s1 and 0 letters in s2 can form 0 letters in s3
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                }
                else if (i == 0) {
                    dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
                }
                else if (j == 0) {
                    dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
                }
                else {
                    // dp[i][j] means use the first i letter in s1, and first j letter in s2
                    // can form first i + j letters in s3.
                    // s3[i + j - 1] means the last letter in current s3 (length i+ j)
                    dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
                }
                    
            }
        }
        return dp[s1.size()][s2.size()];
    }
};