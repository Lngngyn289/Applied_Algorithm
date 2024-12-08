#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7; 
int n;
map<int, int> mp;
int res = 0;

//XB
// int main(){
//   cin >> n;
//   while(n--){
//     int x;
//     cin >> x;
//     mp[x]++;
//   }
//   for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
//     int k = (*it).second;
//     res += k*(k-1)/2;
//      res %= MOD;
//   }
//   cout << res;
// }


//BL
int main(){
  cin >> n;
  while(n--){
    int x; cin >> x;
    mp[x]++;
  }
  map<int,int>::iterator it = mp.begin();
  int prv = (*it).second;
  it++;
  for(; it != mp.end(); it++){
    int cur = (*it).second;
    if(cur - prv == 1){
      res += max(prv, cur);
      res %= MOD;
    }
    prv = cur;
  }
  cout << res;
}