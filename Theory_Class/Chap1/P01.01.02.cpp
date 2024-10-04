#include<bits/stdc++.h>
using namespace std;

int main(){
  queue<int> q;
  string t;
  int v;
  cin >> t;
  while(t != "#"){
    if(t == "PUSH"){
      cin >> v;
      q.push(v);
    }
    else if(t == "POP"){
      if(q.size() == 0) cout << "NULL" << "\n";
      else{
        cout << q.front() << "\n";
        q.pop();
      }
    }
    cin >> t;
  }
}