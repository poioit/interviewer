#include <iostream>

int binSearchLo(vector<int> arr, int x) {
    int lo = 0, hi = arr.size() - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (x > arr[mid]) {
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    return lo;
}

int binSearchHi(vector<int> arr, int x) {
    int lo = 0, hi = arr.size() - 1;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (x < arr[mid]) {
            hi = mid - 1;
        }
        else {
            lo = mid;
        }
    }
    return lo;
}

int main() {
    vector<int> arr = {1,3,5,5,7,9};
    cout << binSearchLo(arr, 3) << endl; // 1
    cout << binSearchLo(arr, 4) << endl; // 2
    cout << binSearchLo(arr, 5) << endl; // 2
    // lower_bound is <=
    // if v exist, return index of v
    // if v not exist, return smallest index of value that > v
    cout << lower_bound(arr.begin(), arr.end(), 3) - arr.begin() << endl; // 1
    cout << lower_bound(arr.begin(), arr.end(), 4) - arr.begin() << endl; // 2
    cout << lower_bound(arr.begin(), arr.end(), 5) - arr.begin() << endl; // 2
    cout << "-------" << endl;
    cout << binSearchHi(arr, 3) << endl; // 1
    cout << binSearchHi(arr, 4) << endl; // 1
    cout << binSearchHi(arr, 5) << endl; // 3
    // upper_bound is >
    // no matter v exist or not
    // return smallest index of value that > v
    cout << upper_bound(arr.begin(), arr.end(), 3) - arr.begin() << endl; // 2
    cout << upper_bound(arr.begin(), arr.end(), 4) - arr.begin() << endl; // 2
    cout << upper_bound(arr.begin(), arr.end(), 5) - arr.begin() << endl; // 4
}
