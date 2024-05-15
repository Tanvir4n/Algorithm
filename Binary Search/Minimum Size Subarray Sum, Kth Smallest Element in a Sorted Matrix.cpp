#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int minLength = INT_MAX;
    int left = 0;
    int sum = 0;

    for (int right = 0; right < n; ++right) {
        sum += nums[right];
        while (sum >= target) {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left++];
        }
    }

    return (minLength == INT_MAX) ? 0 : minLength;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    int minLen = minSubArrayLen(target, nums);
    cout << "Minimum size of subarray with sum at least " << target << ": " << minLen << endl;

    return 0;
}
// ---------------------
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<int> maxHeap;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            maxHeap.push(matrix[i][j]);
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
    }

    return maxHeap.top();
}

int main() {
    vector<vector<int>> matrix = {
        {1,  5,  9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;

    int kth = kthSmallest(matrix, k);
    cout << "The " << k << "th smallest element in the sorted matrix is: " << kth << endl;

    return 0;
}
