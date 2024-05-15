#include <iostream>
#include <vector>
using namespace std;

int searchInRotatedSortedArray(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target)
            return mid;
        
        if (nums[left] <= nums[mid]) { // Left half is sorted
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        } else { // Right half is sorted
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    
    return -1; // Not found
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target;

    cout << "Enter the target element to search in the rotated sorted array: ";
    cin >> target;

    int index = searchInRotatedSortedArray(nums, target);

    if (index != -1)
        cout << "Target found at index " << index << endl;
    else
        cout << "Target not found in the array" << endl;

    return 0;
}
---------
#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] < nums[mid + 1])
            left = mid + 1;
        else
            right = mid;
    }
    
    return left; // Peak element index
}

int main() {
    vector<int> nums = {1, 2, 3, 1}; // Example input array

    int peakIndex = findPeakElement(nums);
    cout << "Peak element found at index " << peakIndex << ": " << nums[peakIndex] << endl;

    return 0;
}
