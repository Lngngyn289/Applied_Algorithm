#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> adj[1001];
void inp(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
}
pair<int,int> bfs(int u){
    int dis[n+1];
    memset(dis,-1,sizeof(dis));
    queue<int> q;
    q.push(u);
    dis[u]=0;
    while(!q.empty()){
        int t=q.front();q.pop();
        for(int it:adj[t]){
            if(dis[it]==-1){
                q.push(it);
                dis[it]=dis[t]+1;
            }
        }
    }
    int maxDis=0;
    int idx;
    for(int i=1;i<=n;i++){
        if(maxDis<dis[i]){
            idx=i;
            maxDis=dis[i];
        }
    }
    return make_pair(idx,maxDis);
}
void longestPathTree(){
    pair<int,int> t1,t2;
    t1=bfs(1);
    t2=bfs(t1.first);
    cout << "Longest path is from " << t1.first << " to "<< t2.first << " of length " << t2.second;
    
}
int main(){
    inp();
    longestPathTree();
    return 0;
}