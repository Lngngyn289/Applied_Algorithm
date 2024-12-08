#include<bits/stdc++.h>
using namespace std;

int a[1000][1000], visited[1000][1000];
int n,m;

int hy[4] = {0,-1,1,0}; // row
int hx[4] = {1,0,0,-1}; // col
int step = 0;
int ok = -1;
map<int,int> stepMap;

// 8 12 5 6
// 1 1 0 0 0 0 1 0 0 0 0 1
// 1 0 0 0 1 1 0 1 0 0 1 1
// 0 0 1 0 0 0 0 0 0 0 0 0
// 1 0 0 0 0 0 1 0 0 1 0 1
// 1 0 0 1 0 0 0 0 0 1 0 0
// 1 0 1 0 1 0 0 0 1 0 1 0
// 0 0 0 0 1 0 1 0 0 0 0 0
// 1 0 1 1 0 1 1 1 0 1 0 1


void bfs(int i, int j) {
  queue<pair<int, int>> q;
  q.push(make_pair(i, j));
  visited[i][j] = 1;
  while (q.size()) {
    pair<int, int> u = q.front();
    q.pop();
    if(stepMap[step] == 0){
      step++;
    }
    stepMap[step]--;
    for (int i = 0; i < 4; i++) {
      int dx = hx[i] + u.second;
      int dy = hy[i] + u.first;
      if (dx < 1 || dx > m || dy < 1 || dy > n) {
        ok = 1;
        return;
      }
      if (a[dy][dx] == 1 || visited[dy][dx] == 1 ) {
        continue;
      }
      stepMap[step+1]++;
      q.push(make_pair(dy, dx));
      visited[dy][dx] = 1;
    } 
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  memset(visited, 0, sizeof(visited));
  int r, c;
  cin >> n >> m >> r >> c;
  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= m; ++j){
      cin >> a[i][j];
    }
  } 
  if(a[r][c] == 1){
    cout << "-1";
    return 0;
  }
  stepMap[0] = 1;
  bfs(r,c);
  if(ok == 1){
    cout << ++step;
  }
  else cout << ok;
}