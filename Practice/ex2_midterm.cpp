#include<bits/stdc++.h>
using namespace std;

int n, K, Q, c,d[13], u[13][13],
f = 0, fbest = 1e9, Cmin = 1e9,
segments = 0, nbR = 0,
y[13], x[13], loadCap[6];
set<int> conflict[13], truck[6];
bool visited[13];


int cnt = 0;

void updateBest(){
  if(f < fbest){
    fbest = min(fbest, f);
    cnt++;
    if(cnt == 3){
      for(int x : truck[1]) cout << x << " ";
      cout << "\n";
      for(int x : truck[2]) cout << x << " ";
      cout << "\n";
    }
  }
}

bool checkX(int v, int k){
  if(v > 0 && visited[v]) return false;
  if (loadCap[k] + d[v] > Q) return false;
  for(int x : conflict[v]){
    if(truck[k].find(x) != truck[k].end()) return false;
  }
  return true;
}

void TryX(int s,int k){
  if(s == 0){
    if(k < K) TryX(y[k+1], k+1);
    return;
  }
  for(int i = 0; i <= n; i++){
    if(checkX(i, k)){
      x[s] = i; visited[i] = true;
      f += u[s][i]; loadCap[k] += d[i];
      segments++;
      truck[k].insert(i);
      if(i > 0){
        if(f + (n+nbR-segments)*Cmin < fbest) TryX(i,k);
      }
      else{
        if(k == K){
          if(segments == n + nbR) updateBest();
        }
        else{
          if(f + (n+nbR-segments)*Cmin < fbest) TryX(y[k+1], k+1);
        }
      }
      visited[i] = false;
      f -= u[s][i];
      loadCap[k] -= d[i];
      segments--;
      truck[k].erase(i);
    }
  }
}

bool checkY(int i, int k){
  if(i == 0) return true;
  if(visited[i]) return false;
  if(loadCap[k] + d[i] > Q) return false;
  return true;
}
void TryY(int k){
  int s = 0;
  if(y[k-1] > 0) s = y[k-1] + 1;
  for(int i = s; i <= n; i++){
    if(checkY(i,k)){
      y[k] = i;
      if(i > 0) segments++;
      visited[i] = true; 
      f += u[0][i];
      loadCap[k] += d[i];
      truck[k].insert(i);
      if(k < K) TryY(k+1);
      else{
        nbR = segments;
        TryX(y[1], 1);
      }
      truck[k].erase(i);
      loadCap[k] -= d[i];
      visited[i] = false;
      f -= u[0][i];
      if(i > 0) segments--;
    }
  }
}

int main(){
  y[0] = 0; d[0] = 0;
  memset(visited, false, sizeof(visited));
  cin >> n >> K >> Q;
  for(int i = 1; i <= n; i++) cin >> d[i];
  for(int i = 0; i <= n; i++)
    for(int j = 0; j <= n; j++){
      cin >> u[i][j];
      if(i != j) Cmin = min(Cmin,u[i][j]);
    } 
  cin >> c;
  while(c--){
    int x, y;
    cin >> x >> y;
    conflict[x].insert(y);
    conflict[y].insert(x);
  }
  TryY(1);
  cout << fbest;
}
