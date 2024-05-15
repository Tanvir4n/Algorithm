//  Finding Insert Position
#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    
    return left;
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

    cout << "Enter the target element to insert: ";
    cin >> target;

    int index = searchInsert(nums, target);

    cout << "The target should be inserted at index " << index << endl;

    return 0;
}
// Searching in Nearly Sorted Array
#include <iostream>
#include <vector>
using namespace std;

int searchInNearlySorted(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target)
            return mid;
        else if (mid > left && nums[mid - 1] == target) // Check left neighbor
            return mid - 1;
        else if (mid < right && nums[mid + 1] == target) // Check right neighbor
            return mid + 1;
        else if (nums[mid] < target)
            left = mid + 2; // Move two steps right
        else
            right = mid - 2; // Move two steps left
    }
    
    return -1; // Not found
}

int main() {
    vector<int> nums;
    int n, target;

    cout << "Enter the number of elements in the nearly sorted array: ";
    cin >> n;

    cout << "Enter " << n << " nearly sorted integers:" << endl;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    }

    cout << "Enter the target element to search: ";
    cin >> target;

    int index = searchInNearlySorted(nums, target);

    if (index != -1)
        cout << "Target found at index " << index << endl;
    else
        cout << "Target not found in the array" << endl;

    return 0;
}
