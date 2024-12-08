#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
pair<int, int> coor[1001];
int treasure[1001];
vector<int> adj[1001];
int mx[1001];

int Try(int i){
  if (mx[i]!=-1){return mx[i];}
  if (adj[i].empty()) return mx[i]=treasure[i];
  int max_value = 0;
  for (int j=0;j<adj[i].size();j++){
    max_value = max(max_value, Try(adj[i][j]));
  }
  return mx[i]=max_value+treasure[i];
}

signed main(){
  cin >> n;
  coor[0]=make_pair(0,0);
  mx[0]=-1;
  treasure[0]=0;
  int temp1,temp2;
  for (int i=1;i<=n;i++){
    cin >> temp1 >> temp2;
    coor[i] = make_pair(temp1,temp2);
    cin >> treasure[i];
    mx[i]=-1;
  }

  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      if (i==j) continue;
      if (coor[i].first<=coor[j].first && coor[i].second<=coor[j].second){
        adj[i].push_back(j);
      }
    }
  }
  int res = Try(0);
  cout << res;
  return 0;
}

// 10
// 2 4 7
// 4 2 10
// 4 6 2
// 5 5 7
// 1 3 9
// 1 5 1
// 1 1 3
// 3 1 5
// 3 3 6
// 2 2 2
