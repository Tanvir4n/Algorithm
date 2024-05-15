#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(){

    int N,P;
    cin>>N>>P;

    vector<int> capacities(N);
    for(int i=0; i<N; i++){
        cin>>capacities[i];
    }

    sort(capacities.begin(), capacities.end());

    int people_fed = 0;
    int days = 0;

    for(int i=0; i<N; i++){
        if(people_fed >= P){
            break;
        }
        people_fed += capacities[i];
        days++;
    }

    if(days == 1){
        cout<<"Tami will be back after 1 day"<<endl;
    } else {
        cout<<"Tami will be back after "<<days<<" days"<<endl;
    } 
}
int main(){

    solution();

    return 0;
}
