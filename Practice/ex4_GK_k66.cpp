#include <bits/stdc++.h>
using namespace std;

int m,n;
int a[1001][1001];
long long dp[1001][1001];

int main(){
  cin >> m >> n;
  for (int i=0;i<m;i++){
    for (int j=0;j<n;j++){
      cin >> a[i][j];
    }
  }
  dp[0][0] = a[0][0];
  for (int i=1;i<m;i++){
    dp[i][0]=dp[i-1][0]+a[i][0];
  }
  for (int i=1;i<n;i++){
    dp[0][i]=dp[0][i-1]+a[0][i];
  }
  for (int i=1;i<m;i++){
    for (int j=1;j<n;j++){
      if (a[i][j]!=0){
        dp[i][j] = min(dp[i-1][j],dp[i][j-1]);
        dp[i][j] = min(dp[i-1][j-1],dp[i][j]);
        dp[i][j] += a[i][j];
      }
      else dp[i][j]=INT32_MAX;
    }
  }
  if (dp[m-1][n-1] > 100000000) dp[m-1][n-1]=-1;
  cout << dp[m-1][n-1];
}

// 5 6
// 1 2 0 5 1 3
// 5 -9 2 0 1 3
// 1 4 1 5 7 4
// -60 1 9 0 29 0
// 6 7 0 5 4 3


// 5 6
// 1 2 0 5 1 3
// 5 -9 2 0 1 3
// 1 4 1 5 7 4
// -60 1 0 0 0 0
// 6 7 0 5 4 3