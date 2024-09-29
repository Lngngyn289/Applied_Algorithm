#include<bits/stdc++.h>
using namespace std;

int X[100], n, k;
int daxet[100];

void in(){
  for(int i = 1; i <= n ; i++){
    cout << X[i] ;
  }
  cout << endl;
}

void Try(int i){
  for(int j = 0 ; j <= 1; j++){
    X[i] = j;
    if(i == n) in();
    else{
      Try(i+1);
    }
  }
}
int main(){
  memset(daxet, 0, sizeof(daxet));
  cin >> n;
  Try(1);
}