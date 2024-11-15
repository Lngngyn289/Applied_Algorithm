#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

int main() {
    faster();
    int n;
    cin >> n;
    vector<pair<int,int>> vt(n);
    vector<pair<int,int>> ans;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vt[i] = {x, y};
    }
    sort(vt.begin(), vt.end(), cmp);
    //ans.push_back({vt[0].first, vt[0].second});
    /*int l = 0;
    for(int i = 1; i < n; i++) {
        if(vt[i].second < ans[l].first) {
            l++;
            ans.push_back({vt[i].first, vt[i].second});
        }
    }*/
    
    //cout << ans.size() << endl;
    int cnt=0,last_seg=-1;
    for(int i=0;i<n;i++){
        if(vt[i].first > last_seg){
            cnt++;
            last_seg=vt[i].second;
        }
    }
    cout<<cnt;
    return 0;
}