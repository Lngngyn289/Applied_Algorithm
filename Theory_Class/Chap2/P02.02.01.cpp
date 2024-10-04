#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, q, i, j; cin >> n;
  int a[n+1], sum[n+1];
  sum[0] = 0;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    sum[i] = sum[i-1] + a[i]; 
  }
  cin >> q;
  while(q--){
    cin >> i >> j;
    cout << sum[j] - sum[i-1] << "\n"; 
  }
}