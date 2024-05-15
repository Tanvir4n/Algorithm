#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

struct Item {
    int weight;
    int tastiness;
};

struct CompareRatio {
    bool operator()(const Item& a, const Item& b) const {
        // Calculate ratios (tastiness-to-weight)
        double ratioA = static_cast<double>(a.tastiness) / a.weight;
        double ratioB = static_cast<double>(b.tastiness) / b.weight;
        
        // Max heap based on ratio (higher ratio is higher priority)
        return ratioA < ratioB; // Note: we use < for max heap
    }
};

double maxTastiness(int N, int K, vector<Item>& items) {
    // Priority queue to store items based on the ratio (max heap)
    priority_queue<Item, vector<Item>, CompareRatio> maxHeap;

    // Push items into max heap based on tastiness-to-weight ratio
    for (const auto& item : items) {
        maxHeap.push(item);
    }

    double totalTastiness = 0.0;
    int remainingCapacity = K;

    // Select items greedily based on the tastiness-to-weight ratio
    while (!maxHeap.empty() && remainingCapacity > 0) {
        Item currentItem = maxHeap.top();
        maxHeap.pop();

        int takeWeight = min(currentItem.weight, remainingCapacity);
        totalTastiness += static_cast<double>(currentItem.tastiness) / currentItem.weight * takeWeight;
        remainingCapacity -= takeWeight;
    }

    return totalTastiness;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<Item> items(N);
    for (int i = 0; i < N; ++i) {
        cin >> items[i].weight >> items[i].tastiness;
    }

    // Calculate maximum tastiness
    double result = maxTastiness(N, K, items);

    // Output the result with 6 decimal places
    cout << fixed << setprecision(6) << result << endl;

    return 0;
}
