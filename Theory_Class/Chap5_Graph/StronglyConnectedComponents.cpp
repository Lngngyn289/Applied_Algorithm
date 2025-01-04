//Tarjan
#include<bits/stdc++.h>
using namespace std;
int n, m, low[100001], num[1000011];
stack <int> st;
vector<int> adj[100001];
int cnt = 0, res = 0;
const int MAX_INT = 1e9;

void tarjan(int u){
  low[u] = num[u] = ++cnt;
  st.push(u);
  for(int v : adj[u]){
    if(num[v] == -1){
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else{
      low[u] = min(low[u], num[v]);
    }
  }
  if(low[u] == num[u]){
    res++;
    while(true){
      int tmp = st.top();
      st.pop();
      num[tmp] = low[tmp] = MAX_INT;
      if(tmp == u) break;
    }
  }
}
int main(){
  memset(num, -1, sizeof(num));
  memset(low, -1, sizeof(low));
  cin >> n >> m;
  for(int i = 0; i < m; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
  }

  for(int i = 1; i <= n; i++){
    if(num[i] == -1){
      tarjan(i);
    }
  }
  cout << res;
}