#include<bits/stdc++.h>
using namespace std;
#define MAX 100004

vector<int>g[MAX];
int par[MAX],dis[MAX],vis[MAX],low[MAX],cs=0;
bool ar[MAX];


void dfs(int u)
{
    vis[u]=1;
    int child=0;
    dis[u]=low[u]=++cs;

    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v]==-1){
            par[v]=u;
            child++;
            dfs(v);
            low[u]=min(low[u],low[v]);
            if(par[u]==-1 && child>1){
                ar[u]=true;
            }
            else if(par[u]!=-1 && low[v]>=dis[u]){
                ar[u]=true;
            }


        }
        else if(v!=par[u]){
            low[u]=min(low[u],dis[v]);
        }

    }


}


int main()
{

    int t,ct=0,n,m,u,v;
    cin>>t;
    while(t--){
        cin>>n>>m;
        cs=0;
        for(int i=0;i<=n;i++){
            g[i].clear();
            par[i]=-1;
            vis[i]=-1;
            ar[i]=false;
        }
        for(int i=0;i<m;i++){
            scanf("%d%d",&u,&v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(vis[i]==-1)dfs(i);
        }

        for(int i=0;i<n;i++){
            if(ar[i])cout<<i<<" ";
        }
        cout<<endl;


    }

    return 0;
}
