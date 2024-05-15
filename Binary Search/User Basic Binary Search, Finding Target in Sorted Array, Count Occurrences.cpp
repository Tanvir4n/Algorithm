#include <iostream>
#include <vector>
using namespace std;

// Basic Binary Search
int binarySearch(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return -1; // Not found
}

// Finding Target in Sorted Array
bool search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target)
            return true;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    
    return false; // Not found
}

// Count Occurrences of Target in Sorted Array
int countOccurrences(vector<int>& nums, int target) {
    int firstIndex = -1;
    int left = 0;
    int right = nums.size() - 1;

    // Find the first occurrence
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] >= target)
            right = mid - 1;
        else
            left = mid + 1;

        if (nums[mid] == target)
            firstIndex = mid;
    }

    if (firstIndex == -1)
        return 0;

    int lastIndex = -1;
    left = 0;
    right = nums.size() - 1;

    // Find the last occurrence
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] <= target)
            left = mid + 1;
        else
            right = mid - 1;

        if (nums[mid] == target)
            lastIndex = mid;
    }

    return lastIndex - firstIndex + 1;
}

int main() {
    vector<int> nums;
    int n, target;

    cout << "Enter the number of elements in the sorted array: ";
    cin >> n;

    cout << "Enter " << n << " sorted integers:" << endl;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    cout << "Enter the target element to search: ";
    cin >> target;

    // Perform basic binary search
    int index = binarySearch(nums, target);
    if (index != -1)
        cout << "Target found at index " << index << endl;
    else
        cout << "Target not found in the array" << endl;

    // Perform search in sorted array
    if (search(nums, target))
        cout << "Target found in the array" << endl;
    else
        cout << "Target not found in the array" << endl;

    // Perform count occurrences of target
    int count = countOccurrences(nums, target);
    cout << "Target occurs " << count << " times in the array" << endl;

    return 0;
}
