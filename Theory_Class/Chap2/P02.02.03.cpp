#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, M;
  cin >> n >> M;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  int l = 0, r = n-1, cnt = 0;
  while(l < r){
    if(a[l] + a[r] < M) l++;
    else if(a[l] + a[r] > M) r--;
    else{
      cnt++;
      l++;
      r--;
    }
  }
  cout << cnt;
}