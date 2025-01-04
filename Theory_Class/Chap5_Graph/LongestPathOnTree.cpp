#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[100001]; 
bool visited[100001]; int n;
pair<int, int> dfs(int u, int dist) {
  visited[u] = true; 
  pair<int, int> farthest = {u, dist}; 
  for (auto [v, w] : adj[u]) {
    if (!visited[v]) { 
      pair<int, int> candidate = dfs(v, dist + w); // Duyệt tiếp đến đỉnh v
      if (candidate.second > farthest.second) farthest = candidate; // Cập nhật đỉnh xa nhất
    }
  }  
  return farthest;
}
void longestPathTree() {
  memset(visited, false, sizeof(visited)); 
  pair<int, int> t1 = dfs(1, 0);
  memset(visited, false, sizeof(visited));
  pair<int, int> t2 = dfs(t1.first, 0);
  cout << t2.second;
}
int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v, w}); 
      adj[v].push_back({u, w});
    }
    longestPathTree();
    return 0;
}
