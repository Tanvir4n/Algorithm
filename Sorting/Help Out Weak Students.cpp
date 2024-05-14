#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(){
    int N;
    cin>>N;

    vector<pair<int, int>> points(N); // (score, ID)

    // Reading input and populating the points vector
    for(int i=0; i<N; i++){
        int ID, score;
        cin>>ID>>score;
        points[i] = {score, ID};
    }

    // Sort points based on scores (first element of each pair)
    sort(points.begin(), points.end());

    // Calculate sum of the three lowest scores
    int sum_of_three_lowest = 0;
    for(int i=0; i<min(N, 3); i++){
        sum_of_three_lowest += points[i].first;
    }

    // Output results based on the sum of the three lowest scores
    if(sum_of_three_lowest < 150){
        cout<<"Counseling Support Required"<<endl;
    } else {
        cout<<"Counseling Support Not Required"<<endl;
        // Output the three lowest scores in ascending order
        for(int i=0; i<min(N, 3); i++){
            cout<<points[i].first<<" ";
        }
        cout<<endl;
    }
}

int main(){

    solution();
    
    return 0;
}
