#include<bits/stdc++.h>
using namespace std;


int main(){
  int n, s; cin >> n >> s;
  int a[n], dp[s+1];
  for(int i = 0; i < n; i++) cin >> a[i];
  dp[0]= 1;
  for(int i = 1; i <= s; i++){
    dp[i] = 0;
    for(int j = 0; j < n; j++){
      if(a[j] <= i) dp[i] = dp[i] + dp[i-a[j]];
    }
  }
  cout << dp[s];
}