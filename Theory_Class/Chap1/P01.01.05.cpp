#include<bits/stdc++.h>
using namespace std;

int main(){
  int n, v ;cin >> n;
  set<int> s;
  while(n--){
    cin >> v;
    s.insert(v);
  }
  string cmd;
  cin >> cmd;

  while(cmd != "#"){
    if(cmd == "min_greater_equal"){
      cin >> v;
      if(s.lower_bound(v) != s.end()) cout << *s.lower_bound(v) << "\n";
      else cout << "NULL\n";
    }
    else if(cmd == "min_greater"){
      cin >> v;
      if(s.upper_bound(v) != s.end()) cout << *s.upper_bound(v) << "\n";
      else cout << "NULL\n";
    }
    else if(cmd == "insert"){
      cin >> v;
      s.insert(v);
    }
    else{
      cin >> v;
      s.erase(v);
    }
    cin >> cmd;
  }
}