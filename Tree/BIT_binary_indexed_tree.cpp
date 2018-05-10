//https://cs.stackexchange.com/questions/10538/bit-what-is-the-intuition-behind-a-binary-indexed-tree-and-how-was-it-thought-a

//https://leetcode.com/problems/range-sum-query-mutable/description/


class NumArray0 {
    vector<int> prefixSum;
public:
    // 1,2,3,4,5
    // 1,3,6,10,15
    // this will timeout
    NumArray0(vector<int> nums) {
        int sum = 0;
        for (int n : nums) {
            sum += n;
            prefixSum.push_back(sum);
        }
    }
    
    void update(int i, int val) {
        int old = 0;
        if (i == 0)
            old = prefixSum[0];
        else
            old = prefixSum[i] - prefixSum[i-1];
        int diff = val - old;
        
        if (diff != 0) {
            for (int j = i; j < prefixSum.size(); j++) {
                prefixSum[j] += diff;
            }
        }
            
    }
    
    int sumRange(int i, int j) {
        if (i < 0 || j < 0 || i >= prefixSum.size() || j >= prefixSum.size())
            return -1;
        if (i == 0) {
            return prefixSum[j];
        }
        else {
            return prefixSum[j] - prefixSum[i-1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

class NumArray {
public:
    //https://cs.stackexchange.com/questions/10538/bit-what-is-the-intuition-behind-a-binary-indexed-tree-and-how-was-it-thought-a
    //https://leetcode.com/problems/range-sum-query-mutable/discuss/75753/Java-using-Binary-Indexed-Tree-with-clear-explanation
    // BIT: binary indexed tree
    // 3 & -3 = 011 & (100+1) = 001, keeps the last 1
    vector<int> values;
    vector<int> BIT;
    int len = 0;
    NumArray(vector<int> nums) {
        len = nums.size();
        values = nums;
        BIT = vector<int>(len+1, 0);
        for (int i = 0; i < len; i++) {
            init(i, nums[i]);
        }
    }
    // bottom up, use zero based index
    void init(int i, int val) {
        i++;
        while (i <= len) {
            BIT[i] += val;
            i += (i&-i);
        }
    }
    
    void update(int i, int val) {
        int diff = val - values[i];
        values[i] = val;
        init(i, diff);
    }
    
    // toward root
    // zero based index
    int get(int i) {
        int rst = 0;
        i++;
        while (i > 0) {
            rst += BIT[i];
            i -= (i&-i);
        }
        return rst;
    }
    
    int sumRange(int i, int j) {
        int l = get(i-1);
        int r = get(j);
        return r-l;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */