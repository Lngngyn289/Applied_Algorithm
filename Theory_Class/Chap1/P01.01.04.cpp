#include<bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  set<int> s;
  while(n--){
    int val; cin >> val;
    s.insert(val);
  }
  string cmd; cin >> cmd;
  while(cmd != "#"){
    int val; cin >> val;
    if(s.upper_bound(val) != s.end()) cout << *(s.upper_bound(val)) << "\n";
    else cout << "-1\n";
    cin >> cmd;
  }
}