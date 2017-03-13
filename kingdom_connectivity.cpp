#include<bits/stdc++.h>
using namespace std;
#define mx 10010
#define ll long long
#define ff first
#define ss second
#define pi pair<int,int>
#define mp make_pair
#define mod 1000000000
vector<int>g[mx];
ll vis[mx],n,s;

ll dfs(int u)
{
    vis[u]=1;
    ll ans=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==n)continue;
        if(vis[v]==1){
            s=v;
            return 1;
        }
        if(!vis[v])ans|=dfs(v);
    }
    vis[u]=2;
    return ans;
}

void bfs(int u)
{
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(!vis[v]){
            vis[v]=vis[u]+1;
            bfs(v);
        }
    }
}

ll f(int u)
{

    if(u==n)return 1;

    if(vis[u]!=-1)return vis[u];
    ll ans=0;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        ans=(ans+f(v))%mod;
    }
    return vis[u]=ans;
}

int main()
{
    int m,u,v;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v;
        g[u].push_back(v);
    }

    if(dfs(1)){
        memset(vis,0,sizeof(vis));
        bfs(s);
        if(vis[n]!=0){
            cout<<"INFINITE PATHS";
            return 0;
        }
    }

    memset(vis,-1,sizeof(vis));
    cout<<f(1);
}



