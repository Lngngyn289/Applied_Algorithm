#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, s; cin >> n >> s;
  int c[n+1];
  int dp[s+1]; dp[0] = 0;
  for(int i = 1; i <= n; i++) cin >> c[i];

  for(int i= 1; i <= s; i++){
    dp[i] = 1e9;
    for(int j = 1; j <= n; j++){
      if(i >= c[j]){
        dp[i] = min(dp[i], dp[i-c[j]] + 1);
      }
    }
  }
  if(dp[s] == 1e9) cout << "-1";
  else cout << dp[s];
}