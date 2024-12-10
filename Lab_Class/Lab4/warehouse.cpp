#include<bits/stdc++.h>
using namespace std;

int n, T, d;
int a[1001], t[1001], dp[1001][101];

int main(){
  cin >> n >> T >> d;
  memset(dp, 0, sizeof(dp));
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++) cin >> t[i];
  
  dp[1][t[1]] = a[1];

  for(int i = 2; i <= n; i++){
    for(int j = max(1,i-d); j <= i-1; j++){
      for(int k = 1; k <= T; k++){
        if(k >= t[i]) dp[i][k] = max(dp[i][k], dp[j][k-t[i]] + a[i]);
      }
    }
  }


  int res = 0;
  for(int i = 1; i <=n; i++){
    for(int j = 1; j <=T; j++){
      res = max(res, dp[i][j]);
      cout << dp[i][j] << " ";
    }
    cout << "\n";
  }
  cout << res;
}
