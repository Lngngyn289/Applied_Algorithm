#include<bits/stdc++.h>
using namespace std;

int n, a[100], dp[100], ans= 0;;

int main(){
  cin>> n;
  for(int i = 0; i < n; i++) cin >> a[i]; 
  for(int i = 1; i < n; i++){
    dp[i] = 1;
    for(int j = 0; j <= i-1; j++){
      if(a[i] > a[j]){
        dp[i] = max(dp[i], dp[j] + 1);
        ans = max(dp[i], ans);
      } 
    }
  }
  cout << ans;
}

