#include<bits/stdc++.h>
using namespace std;

int H, W, n, h[11], w[11], ok = 0;
bool mark[11][11];
bool check(int xStart, int yStart, int hk, int wk){
  for(int i = xStart; i < xStart + hk; i++)
    for(int j = yStart; j < yStart + wk; j++)
      if(mark[i][j]) return false;
  return true;
};
void mark_subrec(int xStart, int yStart, int hk, int wk, bool m){
  for(int i = xStart; i < xStart + hk ; i++)
    for(int j = yStart; j < yStart + wk ; j++)
      mark[i][j] = m;
}
void Try(int k){
  for(int rotate = 0; rotate <= 1; rotate++){
    int hk = h[k];
    int wk = w[k];
    if(rotate == 1){
      int hk = w[k];
      int wk = h[k];
    }
    for(int i = 1; i <= H-hk+1; i++){
      for(int j = 1; j <= W-wk+1; j++){
        if(check(i, j, hk, wk)){
          mark_subrec(i,j,hk,wk, true);
          if(k == n){
            ok = 1;
            return;
          }
          else Try(k+1);
          mark_subrec(i,j,hk,wk, false);
        }
      }
    }
  }
}
int main(){
  memset(mark, false, sizeof(mark));
  cin >> H >> W >> n;
  for (int i = 1; i <= n; i++){
    cin >> h[i] >> w[i];
  }
  Try(1);
  cout << ok;
}