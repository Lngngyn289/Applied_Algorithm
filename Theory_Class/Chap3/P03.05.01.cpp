#include<bits/stdc++.h>
using namespace std;
int n, K, Q, d[13], u[13][13],nbR = 0, f = 0, fbest = 1e9, Cmin = 1e9;
int segments = 0, y[13], x[13], loadCap[6];
bool visited[13];

void updateBest(){
  fbest = min(fbest, f);
}

bool checkX(int v, int k){
  if(v > 0 && visited[v]) return false;
  if (loadCap[k] + d[v] > Q) return false;
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
      if(k < K) TryY(k+1);
      else{
        nbR = segments;
        TryX(y[1], 1);
      }
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
      if(i != j && u[i][j] < Cmin) Cmin = u[i][j];
    } 
  TryY(1);
  cout << fbest;
}