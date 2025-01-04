#include<bits/stdc++.h>
using namespace std;
const int maxP = 256;
int last[maxP];
void computeLast(string p){
    for(int c = 0; c<=255;c++){
      last[c]=0;
    }
    int k = p.length();
    for(int i=k-1;i>=0;i--){
        if(last[p[i]]==0) last[p[i]]=i;
    }
}
int boyerMoore(string P, string T){
    computeLast(P);
    int s=0,cnt=0,N=T.length(),M=P.length();
    while(s<=N-M){
        int j=M-1;
        while(j>=0 && T[j+s]==P[j]){
          j=j-1;
        }
        if(j==-1){
          cnt++;s=s+1;
        }else{
          int k = last[T[j+s]];
          s = s + (j-k>1 ? j-k : 1);
        }
    }
    return cnt;
}
int main(){
    string P,T;
    getline(cin,P);
    getline(cin,T);
    cout<<boyerMoore(P,T);
    return 0;
}