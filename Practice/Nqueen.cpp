#include<bits/stdc++.h>
using namespace std;

int T,n, x[100], cot[100], d1[100], d2[100];
int res;

void Try(int i){
  for(int j = 1; j <= n; j++){
    if(cot[j] && d1[i-j+n] && d2[i+j-1]){
      x[i] = j;
      cot[j] = d1[i-j+n] = d2[i+j-1] = 0;
      if(i == n){
        ++res;
      }
      else Try(i+1);
      cot[j] = d1[i-j+n] = d2[i+j-1] = 1;
    }
  }
}

int main(){
  cin >> T;
  while(T--){
    cin >> n;
    for(int i = 1; i <= 100; i++){
      cot[i] = d1[i] = d2[i] = 1;
    }
    res = 0;
    Try(1);
    cout << res;
  }
}