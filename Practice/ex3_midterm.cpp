#include<bits/stdc++.h>
using namespace std;

#define MOD 1e9+7; 
int n;
map<int, int> mp;
int res = 0;

int main(){
  cin >> n;
  while(n--){
    int x;
    cin >> x;
    mp[x]++;
  }
  for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
    int k = (*it).second;
    res += k*(k-1)/2;
  }
  cout << res;
}