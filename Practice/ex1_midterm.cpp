#include<bits/stdc++.h>
using namespace std;

int n, y, r[21], res, x[21];

void check(){
  int sum = 0;
  for(int i = 1; i <= n; i++) if(x[i] == 1) sum += r[i];
  if(sum >= y) res++;
}

void ktao(){
  for(int i = 1; i <= n; i++) x[i] = 0;
}

void sinh(){
  int i = n;
  for(; i >= 1; i--){
    if(x[i] == 0){
      x[i] = 1;
      for(int j = i + 1; j <= n; j++) x[j] = 0;
      break;
    }
  }
  check();
  if(i == 0) return;
  else sinh();
}

int main(){
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> r[i];
  cin >> y;
  ktao();
  sinh();
  cout << res;
}