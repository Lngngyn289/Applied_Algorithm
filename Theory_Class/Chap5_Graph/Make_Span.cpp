#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e4+1;
int n,m;
int d[maxn];
int indegree[10005];//bac vao
vector<int> adj[10005];
int dp[10004];
void inp(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>d[i];
    for(int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        indegree[y]++;
        adj[x].push_back(y);
    }
}
int topo(){
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(!indegree[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        dp[u]+=d[u];
        for(int x:adj[u]){
            dp[x]=max(dp[x],dp[u]);
            indegree[x]--;
            if(!indegree[x]){
                q.push(x);
            }
        }
    }
    return *max_element(dp+1,dp+n+1);
}
int main(){
    inp();
    cout<<topo();
}