#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int maxi = 5001; 
int n, m;
int c[maxi], d[maxi];
vector<int> adj[maxi];
vector<int> g[maxi];
int dis[maxi];
bool visited[maxi];
void inp() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> d[i];
    }
    for (int i = 0; i < m; i++) {
        int x, y; 
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}

void bfs(int u) {
  queue<int> q; q.push(u);
  visited[u] = true;
  dis[u] = 0;
  while (!q.empty()) {
    int v = q.front(); q.pop();
    for (int x : adj[v]) {
      if (!visited[x] && dis[v] < d[u]) {
        visited[x] = true;
        dis[x] = dis[v] + 1;
        q.push(x);
        g[u].push_back(x);
      }
    }
  }
}
int solve(int s, int t) {
    priority_queue<pii, vector<pii>, greater<pii>> Q;
    vector<int> f(n + 1, INT_MAX);
    f[s] = 0;
    Q.push({0, s});
    while (!Q.empty()) {
        int u = Q.top().second;
        Q.pop();
        if (u == t) return f[u];
        for (int x : g[u]) {
            if (f[x] > f[u] + c[u]) {
                f[x] = f[u] + c[u];
                Q.push({f[x], x});
            }
        }
    }
    return -1;
}
int main() {
    inp();
    for (int i = 1; i <= n; i++) {
      memset(visited, false, sizeof(visited));
      memset(dis, 0, sizeof(dis));
      bfs(i);
    }
    cout << solve(1, n);
    return 0;
}