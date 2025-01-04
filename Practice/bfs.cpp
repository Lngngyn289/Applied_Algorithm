#include<bits/stdc++.h>
using namespace std;

vector<int> ke[1001];
bool visited[1001];
int n,m,s;
void bfs(int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;
    while(!q.empty()){
        int v=q.front();q.pop();
        cout<<v<<" ";
        for(int x:ke[v]){
            if(!visited[x]){
                q.push(x);
                visited[x]=true;
            }
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
    bfs(s);
}
int main(){
    inp();
    return 0;
}