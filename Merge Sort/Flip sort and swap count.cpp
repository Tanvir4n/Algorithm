#include <bits/stdc++.h>
#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& arr, int left, int mid, int right){
    
    vector<int> temp(right - left + 1);
    int i = left; // Starting index for left subarray
    int j = mid + 1; // Starting index for right subarray
    int k = 0; // Starting index to fill temp array
    long long swaps = 0;

    // Merge the two halves into temp array while counting swaps
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // If arr[i] > arr[j], it means there are (mid - i + 1) inversions
            temp[k++] = arr[j++];
            swaps += (mid - i + 1);
        }
    }

    // Copy remaining elements of left subarray
    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    // Copy remaining elements of right subarray
    while (j <= right) {
        temp[k++] = arr[j++];
    }

    // Copy temp array back to original array
    k = 0;
    for (int idx = left; idx <= right; ++idx) {
        arr[idx] = temp[k++];
    }

    return swaps;
}

long long mergeSort(vector<int>& arr, int left, int right) {
    long long totalSwaps = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        // Recursively sort two halves and count swaps
        totalSwaps += mergeSort(arr, left, mid);
        totalSwaps += mergeSort(arr, mid + 1, right);
        // Merge the two sorted halves and accumulate swaps
        totalSwaps += merge(arr, left, mid, right);
    }
    return totalSwaps;
}

int main(){
    int n;
    while(cin >> n){
        vector<int> arr(n);
        for(int i = 0; i < n; ++i){
            cin>>arr[i];
        }

        long long swaps = mergeSort(arr, 0, n - 1);

        cout<<"Minimum exchange operations : "<<swaps<<endl;
    }

    return 0;
}
