#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 201;

vector<int> adj[MAXN];
bool visited[MAXN];

void dfs(int node){
    visited[node] = true;
    for(int neighbor : adj[node]){
        if(!visited[neighbor]){
            dfs(neighbor);
        }
    }
}

bool canVisitAllCountries(int N){
    memset(visited, false, sizeof(visited));
    dfs(0); // Start DFS from country 0
    for(int i = 1; i <= N; ++i){
        if(!visited[i]){
            return false; // If any country from 1 to N is not visited, return false
        }
    }
    return true; // All countries from 1 to N are visited
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, M;
        cin>>N>>M;
        
        // Clear adjacency list for each test case
        for(int i=0; i<=N; i++){
            adj[i].clear();
        }
        
        for(int i=0; i<M; i++){
            int A, B;
            cin>>A>>B;
            adj[A].push_back(B);
            adj[B].push_back(A);
        }
        
        // Check if all countries 1 to N are reachable from country 0
        if(canVisitAllCountries(N)){
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
    }
    
    return 0;
}
/*
Sample
Input	 Output
2         YES
          NO
3 3
0 1
2 0
3 2

4 3
0 1
2 1
3 2

*/
