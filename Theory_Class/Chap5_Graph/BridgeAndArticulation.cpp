#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e5;
int n,m,cnt=0, res_bridge = 0 ,res_ap = 0;
bool ap[maxn];
vector<int> adj[maxn];
int num[maxn],low[maxn] ;
bool visited[maxn];
void dfs_ap(int u, int par){
  num[u] = low[u] = ++cnt;
  visited[u] = true;
  int child = 0;
  for(int v : adj[u]){
    if(!visited[v]){
      dfs_ap(v,u);
      child++;
      low[u] = min(low[u], low[v]);
      if(par != -1 && low[v] >= num[u]) ap[u] = true;
    } else{
      low[u] = min(low[u], num[v]);
    }
  }
  if(par == -1 && child > 1) ap[u] = true;
}
void dfs_bridge(int u, int par){
  num[u] = low[u] = ++cnt;
  visited[u] = true;
  for(int v : adj[u]){
    if(v == par) continue;
    if(!visited[v]){
      dfs_bridge(v,u);
      low[u] = min(low[u], low[v]);
      if(low[v] > num[u]) res_bridge++;
    } else{
      low[u] = min(low[u], num[v]);
    }
  }
}
int main(){
  cin >> n >> m;
  memset(visited, false, sizeof(visited));
  memset(ap, false, sizeof(ap));
  for(int i = 1; i <= m; i++){
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for(int i = 1; i <= n;i++){
    if(!visited[i])dfs_ap(i, -1);
  }
  for(auto i : ap){
    if(i) res_ap++;
  }
  memset(visited, false, sizeof(visited));
  cnt = 0;
  for(int i = 1; i <= n;i++){
    if(!visited[i])dfs_bridge(i, -1);
  }
  cout << res_ap << " " << res_bridge;
}
