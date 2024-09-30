#include<bits/stdc++.h>
using namespace std;

int n, m, a[1000][1000], grid[1000][1000], L[1000], R[1000];

void buildHistogramGrid(){
  for(int j = 0; j < m; j++){
    grid[0][j] = a[0][j];
  }
  for(int i = 1; i < n; i++){
    for(int j = 0; j < m; j++){
      if(a[i][j] != 0){
        grid[i][j] = grid[i-1][j] + 1;
      }
      else grid[i][j] = 0;
    }
  }
}

int maxRecWithThisBottom(int i){
  stack<int> LST;
  for(int j = 0; j < m; j++){
    if(j == 0 ) L[j] = -1;
    else{
      while(!LST.empty() && grid[i][j] <= grid[i][LST.top()]){
        LST.pop();
      }
      if(LST.empty()) L[j] = -1;
      else L[j] = LST.top();
    }
    LST.push(j);
  }

  stack<int> RST;
  R[m-1] = m;
  for(int j = m-1; j >= 0; j--){
    if(j == m-1) R[j] = m;
    else{
      while(!RST.empty() && grid[i][j] <= grid[i][RST.top()]){
        RST.pop();
      }
      if(RST.empty()) R[j] = m;
      else R[j] = RST.top();
    }
    RST.push(j);
  }

  int maxRec = 0;
  for(int j = 0; j < m; j++){
    maxRec = max(maxRec, (R[j] - L[j] - 1)*grid[i][j]);
  } 
  return maxRec;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> a[i][j];

  buildHistogramGrid();
  int res = 0;
  for(int i = 0; i < n; i++){
    res = max(res, maxRecWithThisBottom(i));
  }

  cout << res; 
}