#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, m, q, r1,c1,r2,c2, res;
  cin >> n >> m;
  int a[n+1][m+1], sum[n+1][m+1];
  for(int i = 0; i <= n; i++) sum[i][0] = 0;
  for(int j = 0; j <= m; j++) sum[0][j] = 0;

  for(int i = 1; i <=n; i++){
    for(int j = 1; j <=m; j++){
      cin >> a[i][j];
      sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
    }
  }

  // for(int i = 1; i <=n; i++){
  //   for(int j = 1; j <=m; j++){
  //     cout << sum[i][j] << " ";
  //   }
  //   cout << "\n";
  // }


  cin >> q;
  while(q--){
    cin >> r1 >> c1 >> r2 >> c2;
    res = sum[r2][c2] - sum[r1-1][c2] - sum[r2][c1-1] + sum[r1-1][c1-1];
    cout << res << "\n";
  }
}