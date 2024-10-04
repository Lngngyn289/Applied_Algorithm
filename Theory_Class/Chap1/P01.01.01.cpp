#include<bits/stdc++.h>
using namespace std;

int main(){
  unsigned long long a, b, res;
  cin >> a >> b;
  int rA = a % 10;
  int rB = b % 10;
  a = a/10;
  b = b/10;
  if(rA + rB >= 10) res = a + b + 1;
  else res = a+b;
  if(a+b > 0) cout << res << (rA+rB)%10;
  else cout << (rA+rB)%10;
}