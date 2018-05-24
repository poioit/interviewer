#include <iostream>
void mergeSort(vector<int> &arr, int l, int r);
void merge(vector<int> &arr, int s, int mid, int e);

void mergeSort(vector<int> &arr, int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

void merge(vector<int> &arr, int s, int mid, int e) {
    vector<int> tmp(arr.size(), 0);
    for (int i = s; i <= e; i++)
        tmp[i] = arr[i];
    
    int lS = s;
    int rS = mid + 1;
    int cur = s;
    while (lS <= mid && rS <= e) {
        if (tmp[lS] < tmp[rS]) {
            arr[cur] = tmp[lS];
            lS++;
        }
        else {
            arr[cur] = tmp[rS];
            rS++;
        }
        cur++;
    }
    // only the left half remain need to be copy
    // the right half remain alreay are in the array
    while (lS <= mid) {
        arr[cur++] = tmp[lS++];
    }
}

int main() {
    vector<int> arr = {9,7,5,3,1,10,8,6,4,2};
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    mergeSort(arr, 0, arr.size() - 1);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}