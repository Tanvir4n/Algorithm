#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define pi acos(-1)
#define pb push_back
#define nl "\n"

void ISO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int linear_search(vector<pair<string, string>>phone_book, string src_name){
    for(int i=0; i<phone_book.size(); i++){
        if(phone_book[i].first == src_name){
            return i;                             
        }
    }
    return -1;                                      
}

signed main(){

    vector<pair<string,string>>phone_book;
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        string name,phone_num;
        cin>>name>>phone_num;
        phone_book.push_back({name,phone_num});
    }
        cout<<"Enter the searching contact : ";
        string src_name;
        cin>>src_name;

        int ans = linear_search(phone_book,src_name);
        if(ans==-1){
            cout<<"Contact not found"<<endl;
        }
        else{
            cout<<"Contact found : "<<phone_book[ans].first<<" "<<phone_book[ans].second<<endl;
        }

    ISO();

    return 0;
}
