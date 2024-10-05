#include<bits/stdc++.h>
using namespace std;

int n, a[1000000], maxVal[1000000];

void buildSegmentTree(int id, int l, int r){
  if(l==r){
    maxVal[id] = a[l];
    return;
  }
  int m = (l+r)/2;
  buildSegmentTree(id*2,l,m);
  buildSegmentTree(id*2+1,m+1,r);
  maxVal[id] = max(maxVal[id*2], maxVal[id*2+1]); 
}

int getMax(int id, int l, int r, int i, int j){
  if(i > r || j < l) return 0;
  else if(i <= l && j >= r ) return maxVal[id];
  int m = (l+r)/2;
  int maxLeft = getMax(2*id, l, m, i, j);
  int maxRight = getMax(2*id+1, m+1, r, i, j);
  return max(maxLeft, maxRight);
}

void update(int id, int l, int r, int i, int v){
  if(l > r) return;
  if(i < l || i > r) return;
  else if(l == r){
    maxVal[id] = v;
    return;
  }
  int m = (l+r)/2;
  update(id*2, l, m, i, v);
  update(id*2+1, m+1, r, i, v);
  maxVal[id] = max(maxVal[id*2], maxVal[id*2+1]);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i];
  int m; cin >> m;
  buildSegmentTree(1,1,n);
  while(m--){
    string cmd; cin >> cmd;
    if(cmd == "get-max"){
      int i, j;
      cin >> i >> j; 
      cout << getMax(1,1,n,i,j) << "\n";
    }
    else{
      int i,v;
      cin >> i >> v;
      update(1,1,n,i,v);
    }
  }
}