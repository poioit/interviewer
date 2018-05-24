#include <iostream>

int partition(vector<int> &arr, int s, int e) {
    int pivot = arr[(s+e)/2];
    while (s <= e) {
        while (arr[s] < pivot)
            s++;
        while (arr[e] > pivot)
            e--;
        // the equal sign here is to make the last loop's s++, but not for the swap,
        // the last swap is not necessay
        
        // e.g. pivot 3
        // 4,4,2,3,5,5 (s: 0, e: 3)
        // 3,4,2,4,5,5 (s: 1, e: 2)
        // 3,2,4,4,5,5 (s: 2, e: 1)
        // !!! 3's position is unknown, need to sort the whole left and right part
        if (s <= e) {
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
    }
    return s;
}

void quickSort(vector<int> &arr, int s, int e) {
    int i = partition(arr, s, e);
    // |.........i-1|i.......|
    if (s < i-1) { // need more than two elem
        quickSort(arr, s, i-1);
    }
    if (i < e) {
        quickSort(arr, i, e);
    }
}


int main() {
    vector<int> arr = {9,7,5,3,1,10,8,6,4,2};
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    
    quickSort(arr, 0, arr.size() - 1);
    
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}


//https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class Solution {
public:
    // quick sort partition
    // worst O(n^2), average O(n)
    int findKthLargest(vector<int>& nums, int k) {
        return partition(nums, 0, nums.size() - 1, k);
    }
    
    int partition(vector<int>& nums, int s, int e, int k) {
        int pivot = nums[e];
        // cout << pivot << " s: " << s << ", e:" << e << ", k:" << k << endl;
        int l = s, r = e;
        while (l < r) { // r is pivot, so it's basically empty slot
            if (nums[l] <= pivot) {
                l++;
            }
            else {
                nums[r] = nums[l];
                nums[l] = nums[r-1]; // because we compare l, so move a candidate to l, r is pivot since the beginning, so we use r-1
                r--;
            }
        }
        nums[l] = pivot;
        int largeCount = e - l;
        // find k-th largest
        if (largeCount > k - 1) {
            return partition(nums, r + 1, e, k);
        }
        else if (largeCount < k - 1) {
            return partition(nums, s, l - 1, k - largeCount - 1); // k - (largeCount + 1 pivot)
        }
        return pivot;
    }
};