#include<bits/stdc++.h>
using namespace std;

int main(){
  int res = 0, sum = 0, n, Q;
  cin >> n >> Q;
  int a[n], l = 0, r;
  for(int i = 0; i < n; i++) cin >> a[i];
  for(r = 0; r < n; r++){
    sum += a[r];
    while(sum > Q){
      sum -= a[l];
      l++;
    }
    res = max(r-l+1, res);
  }
  cout << res;
}