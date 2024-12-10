#include<bits/stdc++.h>
using namespace std;

int n, l, r, a[1000001];
int dp[1000001], ans = 0;
deque<int> dq;

int main(){
  cin >> n >> l >> r;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= n; i++){
    while(!dq.empty() && i - r > dq.front()) dq.pop_front();
    if(i - l >= 1){
      while(!dq.empty() && dp[dq.back()] < dp[i-l]) dq.pop_back();
      dq.push_back(i-l);
    }
    dp[i] = a[i] + (dq.empty() ? 0 : dp[dq.front()]);
    ans = max(ans, dp[i]);
  }
  cout << ans;
}