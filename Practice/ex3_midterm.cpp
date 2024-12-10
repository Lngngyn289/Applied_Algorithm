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
  int prv_key = (*it).first;
  int prv_val = (*it).second;
  it++;
  for(; it != mp.end(); it++){
    int cur_key = (*it).first;
    int cur_val = (*it).second;
    if(cur_key - prv_key == 1){
      res += cur_val*prv_val;
      res %= MOD;
    }
    prv_key = cur_key;
    prv_val = cur_val;
  }
  cout << res;
}