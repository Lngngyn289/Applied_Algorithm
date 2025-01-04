#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>  // Định nghĩa pair để lưu chi phí và đỉnh
const int INF = 1e9;  // Sử dụng giá trị vô cùng lớn làm vô hạn
int n, m;  
vector<pair<int, int>> adj[100001]; //Lưu (v, w)
int dist[100001];  // Mảng lưu chi phí ngắn nhất từ s đến tất cả các đỉnh
void dijkstra(int s) {
    fill(dist, dist + n + 1, INF); // Khởi tạo khoảng cách từ s đến tất cả các đỉnh là vô cùng lớn
    dist[s] = 0;  
    priority_queue<pii, vector<pii>, greater<pii>> pq; // Khởi tạo hàng đợi ưu tiên với cặp (chi phí, đỉnh)
    pq.push({0, s});  // Đưa đỉnh s với chi phí 0 vào hàng đợi
    while (!pq.empty()) {
        int u = pq.top().second;  // Lấy đỉnh u có chi phí nhỏ nhất
        int d_u = pq.top().first;  // Chi phí của đỉnh u
        pq.pop();
        if (d_u > dist[u]) continue; // Nếu cphi đỉnh u trong hàng đợi > cphi hiện tại, bỏ qua
        for (auto edge : adj[u]) {
            int v = edge.first;  
            int weight = edge.second;  // Trọng số của cạnh (u, v)
            if (dist[u] + weight < dist[v]) { 
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});  // Thêm cạnh (u, v) với trọng số w
    }
    int s, t;
    cin >> s >> t;
    dijkstra(s);
    if (dist[t] == INF) cout << -1 << endl;
    else  cout << dist[t] << endl;
    return 0;
}
