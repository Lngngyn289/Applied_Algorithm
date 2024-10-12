#include<bits/stdc++.h>
using namespace std;
int n, M, X[1000000], a[1000000];

void solve(){
  X[0] = 1;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= M; j++){
      if(j < a[i]) continue;
      else X[j] += X[j - a[i]];
    }
  }
}

int main(){
  memset(X, 0, sizeof(X));
  cin >> n >> M;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    M -= a[i];
  }
  solve();
  cout << X[M];
}