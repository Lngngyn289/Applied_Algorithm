#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6+1;
int n;
int a[maxn];
void maxSum(int a[],int n){
    vector<ll> dp(n,0);
    dp[0]=ll(a[0]);
    ll ans=-1e6-1;
    for(int i=1;i<n;i++){
        dp[i]=max(ll(a[i]),ll(dp[i-1]+a[i]));
        if(dp[i]%2==0){
            ans=max(ans,dp[i]);
        }
    }
    cout<<ans;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    maxSum(a,n);
    return 0;
}