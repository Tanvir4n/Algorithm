#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

// Comparator for priority queue based on tastiness-to-weight ratio (max heap behavior)
struct CompareRatio{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
        
        double ratioA = static_cast<double>(a.second) / a.first;
        
        double ratioB = static_cast<double>(b.second) / b.first;
        return ratioA < ratioB; // Note: we use < for max heap
    }
};

double maxTastiness(int n, int k, vector<pair<int, int>>& items) {
    // Priority queue to store items based on the ratio (max heap)
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareRatio> maxHeap;

    // Push items into max heap based on tastiness-to-weight ratio
    for (const auto& item : items){
        maxHeap.push(item);
    }

    double totalTastiness = 0.0;
    int remainingCapacity = k;

    // Select items greedily based on the tastiness-to-weight ratio
    while(!maxHeap.empty() && remainingCapacity > 0){
        auto currentItem = maxHeap.top();
        maxHeap.pop();

        int weight = currentItem.first;
        int tastiness = currentItem.second;

        int takeWeight = min(weight, remainingCapacity);
        totalTastiness += static_cast<double>(tastiness) / weight * takeWeight;
        remainingCapacity -= takeWeight;
    }

    return totalTastiness;
}

int main(){

    int n, k;
    cin>>n>>k;

    vector<pair<int, int>> items(n);
    for(int i=0; i<n; i++){
        cin>>items[i].first>>items[i].second; // weight and tastiness
    }

    // Calculate maximum tastiness
    double result = maxTastiness(n, k, items);

    cout<<fixed<<setprecision(6)<<result<<endl;

    return 0;
}
