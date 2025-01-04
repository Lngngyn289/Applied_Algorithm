#include<bits/stdc++.h>
using namespace std;

// 3 2 5
// 0 8 5 1 10 5 9 
// 9 0 5 6 6 2 8
// 2 2 0 3 8 7 2
// 5 3 4 0 3 2 7
// 9 6 8 7 0 9 10
// 3 8 10 6 5 0 2
// 3 4 4 5 2 2 0

int n, k, D;
int load = 0, c[23][23],
cmin = 1e9, f = 0, fbest = 1e9;
map<int,int> mpsg;
set<int> spsg;
bool visited[23];

bool check(int curPos, int i){
  if(visited[i]) return false;
  if(i > n){
    if(visited[i-n] == false) return false;
  }
  else{
    if(load + 1 > k) return false;
  }
  return true;
}

void updateBest(int i){
  for(auto x : mpsg){
    if(x.second < D) return;
  }
  fbest = min(fbest, f+c[i][0]);
}

void Try(int k, int curPos){

  for(int i = 1; i <= 2*n; i++){
    if(check(curPos,i)){
      for(int x : spsg){
        mpsg[x] += c[curPos][i];
      }
      if(i>n) spsg.erase(i-n);
      else spsg.insert(i);
      visited[i] = true;
      f += c[curPos][i];
      if(i > n) load--;
      else load++;
      if(k < 2*n){
        if(f + cmin*(2*n+1-k) < fbest) Try(k+1,i);
      }
      else{
        updateBest(i);
      }
      if(i>n) spsg.insert(i-n);
      else spsg.erase(i);
      for(int x : spsg){
        mpsg[x] -= c[curPos][i];
      }
      visited[i] = false;
      f-= c[curPos][i];
      if(i > n) load++;
      else load--;
    }
  }
}


int main(){
  memset(visited,false,sizeof(visited));
  cin >> n >> k >> D;
  for(int i = 0; i <= 2*n; i++){
    for(int j = 0; j <= 2*n; j++){
      cin >> c[i][j];
      if(i !=j) cmin = min(cmin, c[i][j]);
    }
  }
  Try(1,0);
  cout << fbest;
}