#include<bits/stdc++.h>
using namespace std;

vector<int> T[50];
int m, n, X[50], load[50], res=1e9;
bool conflict[50][50];

void input(){
  cin >> m >> n;
  for(int t = 1; t <= m; t++){
    int k;
    cin >> k;
    for(int i = 1; i <= k; i++){
      int c; cin >> c;
      T[c].push_back(t);
    }
  }
  memset(conflict, false, sizeof(conflict));
  int K; cin >> K;
  for(int u = 1; u <= K; u++){
    int i, j; cin >> i >> j;
    conflict[i][j] = true; conflict[j][i] = true;
  }
}

bool check(int t, int k){
  for(int i = 1; i <= k-1; i++)
    if(conflict[i][k] && X[i] == t) return false;
  return true;
}

void solution(){
  int maxLoad = 0;
  for(int t = 1; t <= m; t++){
    maxLoad = max(maxLoad,load[t]);
  }
  if(maxLoad < res) res = maxLoad;
}

void Try(int k){
  for(int i = 0; i < T[k].size(); i++){
    int t = T[k][i];
    if(check(t,k)){
      X[k] = t;
      load[t]++;
      if(k == n) solution();
      else{
        if(load[t] < res) Try(k+1);
      }
      load[t]--;
    }
  }
}


int main(){
  input();
  memset(load, 0, sizeof(load));
  Try(1);
  if(res == 1e9) cout << res;
  else cout << "-1";
}