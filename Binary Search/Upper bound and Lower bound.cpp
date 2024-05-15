#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    // Input array elements
    std::vector<int> arr(n);
    std::cout << "Enter " << n << " elements in ascending order:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Target value input
    int target;
    std::cout << "Enter the target value to find its lower and upper bounds: ";
    std::cin >> target;

    // Find lower bound and upper bound
    auto lower = std::lower_bound(arr.begin(), arr.end(), target);
    auto upper = std::upper_bound(arr.begin(), arr.end(), target);

    // Convert iterators to indices
    int lowerIndex = lower - arr.begin();
    int upperIndex = upper - arr.begin();

    // Output results
    std::cout << "Lower bound of " << target << " is at index: " << lowerIndex << std::endl;
    std::cout << "Upper bound of " << target << " is at index: " << upperIndex << std::endl;

    return 0;
}
