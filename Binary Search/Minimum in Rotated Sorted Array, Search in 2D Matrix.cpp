#include <iostream>
#include <vector>
using namespace std;

int findMinInRotatedSortedArray(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] < nums[right])
            right = mid; // Search in the left half
        else
            left = mid + 1; // Search in the right half
    }
    
    return nums[left]; // Minimum element
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; // Example rotated sorted array

    int minElement = findMinInRotatedSortedArray(nums);
    cout << "Minimum element in the rotated sorted array: " << minElement << endl;

    return 0;
}
// ------------------
#include <iostream>
#include <vector>
using namespace std;

bool searchIn2DMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty())
        return false;

    int rows = matrix.size();
    int cols = matrix[0].size();

    int left = 0;
    int right = rows * cols - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / cols][mid % cols];

        if (midValue == target)
            return true;
        else if (midValue < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    }; // Example 2D matrix

    int target;
    cout << "Enter the target element to search in the 2D matrix: ";
    cin >> target;

    bool found = searchIn2DMatrix(matrix, target);

    if (found)
        cout << "Target element found in the 2D matrix" << endl;
    else
        cout << "Target element not found in the 2D matrix" << endl;

    return 0;
}

