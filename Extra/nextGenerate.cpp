#include<bits/stdc++.h>
using namespace std;

int n, x[100], k;
bool ok = true;

void init(){
  for(int i = 1; i <= n; i++){
    x[i] = i;
  }
}

void generate(){
  int i = n-1;
  while(x[i] > x[i+1]  && i > 0){
    --i;
  }
  if(i == 0) ok = false;
  else{
    for(int j = n; j > i; j--){
      if(x[j] > x[i]){
        swap(x[j], x[i]);
        reverse(x+i+1, x+n+1);
        break;
      }
    }
  }
}

void print(){
  for(int i = 1; i <= n; i++){
    cout << x[i] << " ";
  }
  cout << endl;
}

int main(){
  cin >> n >> k;
  init();
  while(ok){
    print();
    generate();
  }
}