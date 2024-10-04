#include<bits/stdc++.h>
using namespace std;

int main(){
  stack<int> s;
  string t;
  int v;
  cin >> t;
  while(t != "#"){
    if(t == "PUSH"){
      cin >> v;
      s.push(v);
    }
    else if(t == "POP"){
      if(s.size() == 0) cout << "NULL" << "\n";
      else{
        cout << s.top() << "\n";
        s.pop();
      }
    }
    cin >> t;
  }
}