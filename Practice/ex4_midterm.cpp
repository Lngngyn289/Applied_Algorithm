#include<bits/stdc++.h>
using namespace std;

int n, m, ok = 0, res = 0 ;
int hx[3] = {0, 1, 1};
int hy[3] = {1, 0, 1};
int a[1001][1001];

void Try(int i, int j, int sum){
  if(i == n && j == m){
    ok = 1;
    res = min(sum, res);
    return;
  }
  if(i + 1 <= n && a[i+1][j] != 0){
    Try(i+1,j, sum + a[i+1][j]);
  }
  if(j + 1 <= m && a[i][j+1] != 0){
    Try(i,j+1, sum + a[i][j+1]);
  }
  if(j + 1 <= m && i + 1 <= n && a[i+1][j+1] != 0){
    Try(i+1,j+1, sum + a[i+1][j+1]);
  }
}

int main(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      cin >> a[i][j];
    }
  }
  Try(1,1,a[1][1]);
  if(!ok) cout << "-1";
  else cout << res;
}

// 5 6
// 1 2 0 5 1 3
// 5 -9 2 0 1 3
// 1 4 1 5 7 4
// -60 1 0 0 0 0
// 6 7 0 5 4 3

// 5 6
// 1 2 0 5 1 3
// 5 -9 2 0 1 3
// 1 4 1 5 7 4
// -60 1 9 0 29 0
// 6 7 0 5 4 3
