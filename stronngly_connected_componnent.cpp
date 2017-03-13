#include<bits/stdc++.h>
using namespace std;
#define MAX 50010
vector<int>g[MAX];
vector<int>gr[MAX];
stack<int>s;
int vis[MAX],bel[MAX],cnt[MAX],mx,id;


void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v]==-1){
            dfs(v);
        }

    }
    s.push(u);
}

void dfs2(int u,int b)
{
    bel[u]=b;
    vis[u]=1;
    cnt[b]++;
    for(int i=0;i<gr[u].size();i++){
        int v=gr[u][i];
        if(vis[v]==-1){
            dfs2(v,b);
        }
    }
    return;
}

int dfs3(int u)
{
    int ans=0;
    for(int i=0;i<gr[u].size();i++){
        int v=gr[u][i];
        if(vis[v]!=-1)ans+=vis[v];
        else{
            ans+=dfs3(v);
        }
    }

    vis[u]=cnt[bel[u]]+ans;
    if(vis[u]>mx){
        mx=vis[u],id=u;
    }
    else if(vis[u]==mx){
        id=min(id,u);
    }
    return vis[u];
}

int main()
{

    int n,m,u,v,t,ct=0;
    cin>>t;
    while(t--){
        cin>>n;
        m=n;
        mx=-1;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<=n;i++){
            g[i].clear();
            gr[i].clear();
        }

        for(int i=0;i<m;i++){
            cin>>u>>v;
            g[u].push_back(v);
            gr[v].push_back(u);

        }
        memset(vis,-1,sizeof(vis));

        for(int i=1;i<=n;i++){
            if(vis[i]==-1)dfs(i);
        }

        int mark=0;
        memset(vis,-1,sizeof(vis));
        while(!s.empty()){
            int u=s.top();
            s.pop();
            if(vis[u]==-1){
                mark++;
                dfs2(u,mark);
            }
        }
        for(int i=0;i<=n;i++)gr[i].clear();
        for(int i=1;i<=n;i++){
            if(g[i].size()>0){
                int v=g[i][0];

                if(bel[v]!=bel[i])gr[i].push_back(v);
            }
        }

        memset(vis,-1,sizeof(vis));
        for(int i=1;i<=n;i++){
            if(vis[i]==-1)int ans=dfs3(i);
        }
        //for(int i=1;i<=n;i++)cout<<bel[i]<<" ";
        printf("Case %d: %d\n",++ct,id);

    }
}
