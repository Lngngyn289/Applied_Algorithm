#include<bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
bool visited[1001];
int n,m,s;
void dfs(int u){
    cout<<u<<" ";
    visited[u]=true;
    for(int x : ke[u]){
        if(!visited[x]){
          dfs(x);
        }
    }
}
void inp(){
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    for(int i=1;i<=n;i++) sort(ke[i].begin(),ke[i].end());
    memset(visited,false,sizeof(visited));
    dfs(s);
}
int main(){
    inp();
}