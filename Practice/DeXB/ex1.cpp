#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, ans = 0, res = 0; 
  cin >> n;
  int a[n], rm = 3;

  for(int i = 0; i< n; i++){
    cin >> a[i];
    if(a[i] % 2 && rm != 1) {
      res++;
      rm = 1;
    }
    else if( a[i] % 2 == 0 && rm != 0){
      res++;
      rm = 0;
    }
    else{
      ans = max(ans, res);
      rm = a[i] % 2;
      res = 1;
    }
  }
  ans = max(res, ans);
  cout << ans;
}