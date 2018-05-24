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



struct SegmentTreeNode {
	int s, e, sum;
	SegmentTreeNode* left; 
	SegmentTreeNode* right;
	SegmentTreeNode(int _s, int _e) : s(_s), e(_e), sum(0), left(NULL), right(NULL) {}
};

class SegmentTree {
public:
	SegmentTree(vector<int>& nums) {
		int n = nums.size();
		root = buildST(nums, 0, n - 1);
	}

	void update(int i, int val) {
		update(root, i, val);
	}

	int sumRange(int i, int j) {
		return sumRange(root, i, j);
	}
private:
	SegmentTreeNode* root;
	SegmentTreeNode* buildST(vector<int>& nums, int s, int e) {
		if (s > e)
            return NULL;
        SegmentTreeNode* res = new SegmentTreeNode(s, e);
        if (s == e) {
            res->sum = nums[s];
            return res;
        }
        int m = s + (e - s) / 2;
        res->left = buildST(nums, s, m);
        res->right = buildST(nums, m + 1, e);
        res->sum = res->left->sum + res->right->sum;
        return res;
	}
	void update(SegmentTreeNode* root, int i, int val) {
		if (root->s == root->e)
            root->sum = val;
		else {
			int m = root->s + (root->e - root->s) / 2;
			if (i <= m)
                update(root->left, i, val);
			else
                update(root->right, i, val);
			root->sum = root->left->sum + root->right->sum;
		}
	}
	int sumRange(SegmentTreeNode* root, int s, int e) {
		if (root->s == s && root->e == e)
            return root->sum;
		else {
			int m = root->s + (root->e - root->s) / 2;
			if (e <= m)
                return sumRange(root->left, s, e);
			else if (s >= m + 1)
                return sumRange(root->right, s, e);
			else
                return sumRange(root->left, s, m) + sumRange(root->right, m + 1, e);
		}
	}
};

class NumArray {
public:
	NumArray(vector<int> nums) {
		st = new SegmentTree(nums);
	}

	void update(int i, int val) {
		st->update(i, val);
	}

	int sumRange(int i, int j) { 
		return st->sumRange(i, j);
	}
private: 
	SegmentTree* st;
};