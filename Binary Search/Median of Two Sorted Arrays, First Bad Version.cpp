#include <iostream>
#include <vector>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int totalSize = nums1.size() + nums2.size();
    if (totalSize % 2 == 1) {
        return findKthElement(nums1, 0, nums2, 0, totalSize / 2 + 1);
    } else {
        return (findKthElement(nums1, 0, nums2, 0, totalSize / 2)
                + findKthElement(nums1, 0, nums2, 0, totalSize / 2 + 1)) / 2.0;
    }
}

int findKthElement(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k) {
    if (start1 >= nums1.size()) {
        return nums2[start2 + k - 1];
    }
    if (start2 >= nums2.size()) {
        return nums1[start1 + k - 1];
    }
    if (k == 1) {
        return min(nums1[start1], nums2[start2]);
    }

    int mid1 = (start1 + k / 2 - 1 < nums1.size()) ? nums1[start1 + k / 2 - 1] : INT_MAX;
    int mid2 = (start2 + k / 2 - 1 < nums2.size()) ? nums2[start2 + k / 2 - 1] : INT_MAX;

    if (mid1 < mid2) {
        return findKthElement(nums1, start1 + k / 2, nums2, start2, k - k / 2);
    } else {
        return findKthElement(nums1, start1, nums2, start2 + k / 2, k - k / 2);
    }
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median of the two sorted arrays is: " << median << endl;

    return 0;
}
// -----------
#include <iostream>
using namespace std;

bool isBadVersion(int version); // Assume this function is provided

int firstBadVersion(int n) {
    int left = 1;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (isBadVersion(mid)) {
            right = mid; // Look for earlier bad versions
        } else {
            left = mid + 1; // Look for later bad versions
        }
    }

    return left; // The first bad version
}

int main() {
    int n = 10; // Example total number of versions
    int firstBad = firstBadVersion(n);
    cout << "The first bad version is: " << firstBad << endl;

    return 0;
}
