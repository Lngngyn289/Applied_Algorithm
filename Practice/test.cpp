
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int n;
int a[N], s = 0;
int count_event = 1, count_odd = 0, res = 0;
void nhap()
{
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
}
void solve()
{
  for(int i = 1; i <= n; i++)
  {
    s += a[i];
    if(s % 2 == 0){
        res = (res + count_event) % MOD;
        count_event++;
    }
    else{
      res = (res + count_odd) % MOD;
      count_odd++;
    }
  }
  cout << res << endl;
}
int main()
{
  nhap();
  solve();
  return 0;
}

