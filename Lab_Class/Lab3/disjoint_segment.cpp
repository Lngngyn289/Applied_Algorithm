#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

bool cmp(pair<int,int> a, pair<int,int>b){
    return a.second < b.second;
}

int main() {
    vector<pair<int,int>> v;
    int n; cin >> n;
    while(n--){
        int a, b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end(), cmp);
    int cnt = 0, lastSegment = -1;
    for(int i = 0; i < v.size(); i++){
        if(v[i].first > lastSegment){
            cnt++;
            lastSegment = v[i].second;
        }
    } 
    cout<<cnt << "\n";

}