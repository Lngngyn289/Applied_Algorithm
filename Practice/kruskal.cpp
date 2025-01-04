#include<bits/stdc++.h>
using namespace std;
using ll=long long;

struct edge{
    int x,y,w;
};

int n,m;
int sz[100001],parent[100001];
vector<edge> dscanh;
void ktao(){
    for(int i=1;i<=n;i++){
        sz[i]=1;
        parent[i]=i;
    }
}

int find(int u){
    if(u==parent[u]) return u;
    else return parent[u]=find(parent[u]);
}
bool union_1(int u,int v){
    u=find(u);
    v=find(v);
    if(u==v) return false;
    if(sz[u]>sz[v]){
        parent[v]=u;
        sz[u]+=sz[v];
    }else{
        parent[u]=v;
        sz[v]=sz[u];
    }
    return true;
}
void nhap(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y,w;cin>>x>>y>>w;
        dscanh.push_back((edge){x,y,w});
    }
}
bool cmp(edge a, edge b){
    return a.w < b.w;
}

void kruskal(){
    sort(dscanh.begin(),dscanh.end(),cmp);
    int d=0;
    vector<edge> MST;//luu cay khung
    for(int i=0;i<m;i++){
        if(MST.size()==n-1) break;
        edge e=dscanh[i];
        //kiem tra e co tao thanh chu trinh hay ko
        if(union_1(e.x,e.y)){
            MST.push_back(e);
            d+=e.w;
        }
    }
    if(MST.size()<n-1){
        cout<<"IMPOSIBLE";return;
    }
    else cout<<d<<endl;
    for(auto it:MST){
        cout<<it.x<<' '<<it.y<<' '<<it.w<<endl;
    }
}
int main(){
    nhap();ktao();
    kruskal();
}
/*
input:
6 9  
1 2 1
1 3 2
3 2 3  
2 4 4
2 5 7
3 5 5
4 5 3
4 6 2
5 6 2
*/