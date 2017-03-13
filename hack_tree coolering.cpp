#include<bits/stdc++.h>
using namespace std;
#define MAX 100006
#define ll long long
#define mod 1000000007
vector<int>g[MAX];
int vis[MAX];

int dfs(int u)
{
    vis[u]=1;
    ll ans=1;
    int cnt=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v]==-1){

            ans=(ans*cnt)%mod;
            cnt++;
            ans=(ans*dfs(v))%mod;
        }

    }
    return ans;
}

int main()
{
    int t,n,u,v;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<=n;i++)g[i].clear();
        for(int i=0;i<n-1;i++){
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }

        memset(vis,-1,sizeof(vis));
        cout<<dfs(1)<<endl;

    }
}
